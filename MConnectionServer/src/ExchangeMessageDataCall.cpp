/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExchangeMessageDataCall.cpp
 * Author: trungthanh
 * 
 * Created on July 24, 2017, 4:25 PM
 */

#include "ExchangeMessageDataCall.h"
#include "RtMessageModel.h"

#include <iostream>
using namespace std;


#include <functional>
class CustomFuncCallback:public CallProcessorIf
{
public:
    CustomFuncCallback( const std::function< void (void ) >&  f , ExchangeMessageDataCall* aPtr = NULL):_f(f), _ptr(aPtr) {}
    std::function< void (void ) > _f;
    ExchangeMessageDataCall* _ptr;
    
    void Proceed() {
        //cout<<"CustomFuncCallback "<<endl;
        if (_f)            
            _f();
        else
            cout<<"null function _f"<<endl;
        delete this;
    }
    virtual void Failed() {
        if (_ptr)
            _ptr->Failed();
        delete this;
    }
};



ExchangeMessageDataCall::~ExchangeMessageDataCall() {
}



void ExchangeMessageDataCall::Proceed()
{
    cout<<"RequestexchangeMessages ..."<<endl;
    _service->RequestexchangeMessages(&this->_context
        , &_stream
        , _cq // call completion queue. Khi nhận/gửi đc message mới nó sẽ thông qua queue này 
        , _cq // connection mới gọi vào hàm exchangeMessages sẽ gọi qua hàm này. 
        , (void *)( (new CustomFuncCallback(
            [this](){
                this->clone()->Proceed();// Tạo call mới để sẵn sàng cho request tiếp theo .
                // có cuộc gọi đến , bắt đầu đọc authenticating m
                cout<<"incomming exchange request from peer "<<_context.peer()<<endl;
                
                cout<<"read authenticating ..."<<endl;
                _stream.Read(&client2ServerMsg, (new CustomFuncCallback([this]()
                            {
                                // Đọc xong authenticate message ở đây 

                                cout <<" authenticating read done, checking... "<<endl;
                                bool authenticated = false;
                                cout<<"test session key: "<< client2ServerMsg.authmessage().sessionkey()<<endl;

                                realtime::messageservice::AuthenticateReply& authReply = *server2ClientMsg.mutable_authreply();

                                if (client2ServerMsg.type() != realtime::messageservice::C2SMessage::EAuthenticate )
                                {
                                    authReply.set_authenticated(false);
                                    server2ClientMsg.set_commonmessage("Not authenticated");
                                } 
                                else if (RtMessageModel::instance()->checkSession(
                                        client2ServerMsg.authmessage() ))
                                { // check authenticated information
                                    uid = client2ServerMsg.authmessage().userid();
                                    std::string session = client2ServerMsg.authmessage().sessionkey();
                                    cout<<"uid: "<<uid<<" session key : "<<session<<endl;
                                    
                                    //Todo: redo this: auto enable session ok 
                                    authReply.set_sessionkey(session);
                                    authReply.set_userid( client2ServerMsg.authmessage().userid() );
                                    authReply.set_authenticated(true);
                                    authenticated = true;
                                    
//                                    RtMessageModel::instance()->addUserConnection(
//                                            client2ServerMsg.authmessage().userid(), this 
//                                            );
                                    

                                }

                                // write to s2c 

                                if (authenticated){
                                    _status = EStreaming;
                                    // map the call to user.
                                    //this->streamProcess();
                                    
                                }
//                                this->SendMessage(server2ClientMsg);
                                this->_sendingStatus = ESending;
                                if (authenticated)
                                    RtMessageModel::instance()->addUserConnection(
                                            client2ServerMsg.authmessage().userid(), this 
                                            );
                                
                                _stream.Write(server2ClientMsg, (new CustomFuncCallback(
                                [this](){
                                    _sendingStatus = EStart; // write complete
                                    
                                    this->streamProcess();
                                }
                                , this ))->getMeBase() );
                            }, this) 

                    ) ->getMeBase()
                 );
            }
          ) )->getMeBase() ) 

    );    


}



void ExchangeMessageDataCall::streamProcess()
{
    /// read message and push to store;
    static int i = 0;
    cout<<"streaming loop "<<i++<<endl;
    _stream.Read(&this->client2ServerMsg, 
        ( new CustomFuncCallback(
                [this]() {
                    
                    ::RtMessageModel::instance()->processUserMessage(uid, client2ServerMsg);

                    cout<<uid <<" server received message: "<<client2ServerMsg.txt().text()<<endl;
//                    // push to model for processing 
//                    
                    //write a test pong 
//                    this->server2ClientMsg.mutable_txt()->set_text("Hello you, I reply here from server {" 
//                            + client2ServerMsg.txt().text() + "} " );
//                    this->SendMessage(server2ClientMsg);
                    this->streamProcess();
                }
            
            , this )
        )->getMeBase() 
    ) ;
    
}


void ExchangeMessageDataCall::SendMessage(const realtime::messageservice::S2CMessage& aMessage)
{
    //std::lock_guard<std::mutex> aLock(queueMutex);
    cout<<"send back to client status:"<<_sendingStatus<<" this: "<<this<<endl;
    
    if (_sendingStatus != ESending)
    {
            cout<<"send back to client 2"<<endl;

        _sendingStatus = ESending;
        _stream.Write(aMessage ,
                (new CustomFuncCallback( ([this](){
                    cout<<"send done "<<endl;
                    realtime::messageservice::S2CMessage aMsg;
                    bool nonEmpty = false; 
                    
                    {
                        //std::lock_guard<std::mutex> aLock2(queueMutex);
                        _sendingStatus = EStart;
                    
                        if (sendingQueue.size() > 0 )
                        {
                            cout<<"send back to client 3"<<endl;
                            
                            nonEmpty = true;
                            aMsg.Swap(&sendingQueue.front());
                            sendingQueue.pop();
                        }
                    }
                    if (nonEmpty)
                    {
                        SendMessage(aMsg);
                    }
                
                } ) , this ) )->getMeBase() );
    } 
    else {
        cout<<"send back to client 4"<<endl;
        
        sendingQueue.push(aMessage);
    }
}

void ExchangeMessageDataCall::Failed()
{
    cout<< "Failed connection , remove uid conn "<<uid<<endl;
    RtMessageModel::instance()->removeUserConnection(
            uid, this 
            );
//    _stream.Finish(grpc::Status::CANCELLED, NULL);
//    delete this;
    
}
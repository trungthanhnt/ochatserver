/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exchangeMessageClient.cpp
 * Author: trungthanh
 *
 * Created on July 25, 2017, 12:19 PM
 */

#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <thread>

#include <grpc++/grpc++.h>
using namespace std;
#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "rpc/messageservice.grpc.pb.h"
#endif
/*
 * Simple C++ Test Suite
 */
using namespace grpc;
using namespace realtime::messageservice;

class StreamingClient {
 public:
  StreamingClient(std::shared_ptr<Channel> channel)
      : _stub(realtime::messageservice::MessageService::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string exchangeMessagesTest(protobuf::int64 uid,  const std::string& user) {
    // Data we are sending to the server.
//    HelloRequest request;
//    request.set_name(user);
//
//    // Container for the data we expect from the server.
//    HelloReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;
    

    // The actual RPC.
    std::unique_ptr< ::grpc::ClientReaderWriter< ::realtime::messageservice::C2SMessage,
            ::realtime::messageservice::S2CMessage>>  clientRWr = _stub->exchangeMessages(&context);
            
    C2SMessage aC2SMessage;
    AuthenticateMessage* aAuthMsg = aC2SMessage.mutable_authmessage();
    aAuthMsg->set_userid(uid);
    aAuthMsg->set_sessionkey("KeepMovingForward-NeverStop");
    
    
    clientRWr->Write(aC2SMessage);
    
    S2CMessage aServerMsg;
    
    if ( clientRWr->Read(&aServerMsg ) )
    {
        cout<<"got message "<<endl;
        if (aServerMsg.has_authreply() ) {
            cout<< "auth reply"<< aServerMsg.authreply().userid()<<endl
                    <<"session:" <<aServerMsg.authreply().sessionkey()<<endl;
            
        }
        else
            cout<<"no auth reply"<<endl;
    } 
    else 
    {
        cout<<"no read message"<<endl;
    }

    std::thread t( [&clientRWr,&aServerMsg, uid]()
            {
                int i = 0;
                while (i < 100 && clientRWr->Read(&aServerMsg)  )
                {
                    i++;
                    cout<<uid<<" received from uid:"<<aServerMsg.base().fromuid()<<" msg: " << aServerMsg.txt().text()<<endl;
                }
                cout<<"end of read loop" <<endl;
            }
        );    
       
    
    cout<<"writing 100 messages"<<endl;
    for (int i = 0 ; i < 100; i++)
    {
        C2SMessage aC2SMessage;
        TextMessage& aText = * aC2SMessage.mutable_txt();
        
        stringstream ss;
        ss<<"this is my message "<<uid<<" "<<user<<" i "<<i;
        
        aText.set_text(ss.str());
//        aText.mutable_base()->set_fromuid(uid);
//        aText.mutable_base()->set_userid(2017);
        
        aC2SMessage.mutable_base()->set_userid(uid + 1);
        aC2SMessage.mutable_base()->set_fromuid(uid);
        clientRWr->Write(aC2SMessage);
        //usleep(100000);
    }
    
  
    t.join();
    clientRWr->WritesDone();
  }

 private:
  std::unique_ptr<realtime::messageservice::MessageService::Stub> _stub;
};

int main(int argc, char** argv) {

    for (int i = 0; i < 100; i ++) {
        thread *t = new thread ([i](){
            StreamingClient aClient(grpc::CreateChannel(
              "localhost:50051", grpc::InsecureChannelCredentials()) );
            aClient.exchangeMessagesTest(i, "thanh");
            cout<<"done "<<endl;

        });
    }
//    
    StreamingClient aClient(grpc::CreateChannel(
      "localhost:50051", grpc::InsecureChannelCredentials()) );
    aClient.exchangeMessagesTest(3456, "thanh");
    cout<<"done "<<endl;

    return (EXIT_SUCCESS);
}


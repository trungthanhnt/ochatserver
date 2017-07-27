/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExchangeMessageDataCall.h
 * Author: trungthanh
 *
 * Created on July 24, 2017, 4:25 PM
 */

#ifndef EXCHANGEMESSAGEDATACALL_H
#define EXCHANGEMESSAGEDATACALL_H
#include "AbstractCallData.h"
#include <rpc/messageservice.pb.h>
#include <rpc/messageservice.grpc.pb.h>

#include <queue>
#include <deque>
#include <mutex>


class ExchangeMessageDataCall 
: public AbstractCallData<realtime::messageservice::MessageService::AsyncService> 
{
public:
    
    typedef AbstractCallData<realtime::messageservice::MessageService::AsyncService> _Base;
    using _Base::startAcceptingCall;
    
    ExchangeMessageDataCall(realtime::messageservice::MessageService::AsyncService* aSvr, grpc::ServerCompletionQueue* aCq)
    :_Base(aSvr, aCq) 
    ,_status(EStart)
    ,_sendingStatus(EStart)
    ,_stream(&_context)
    
    {
        
    }
    
    virtual ~ExchangeMessageDataCall();
    
    virtual _Base* clone() {
        return new ExchangeMessageDataCall(_Base::_service, _cq);
    };
    
    virtual void Proceed();
    
    virtual void Failed();
    
    void SendMessage(const realtime::messageservice::S2CMessage& aMessage);
    
private:
    ExchangeMessageDataCall(const ExchangeMessageDataCall& orig);
    //void authenticate();
    void streamProcess();
    
    enum TStatus{
        EStart,
        EAuthenticating,
        EReadAuthenticatingMsg,
        EWriteAutheticatedResult,
        EProcessing,
        ESending,
        EReceiving,
        EStreaming, 
        EFinish,
    };
    
    TStatus _status;
    TStatus _sendingStatus;
    
    ::grpc::ServerAsyncReaderWriter< ::realtime::messageservice::S2CMessage, ::realtime::messageservice::C2SMessage> _stream;
    realtime::messageservice::C2SMessage client2ServerMsg;
    
    realtime::messageservice::S2CMessage server2ClientMsg;
        
    int64_t uid;
    
    std::queue<realtime::messageservice::S2CMessage > sendingQueue;
    std::mutex queueMutex;

};

#endif /* EXCHANGEMESSAGEDATACALL_H */


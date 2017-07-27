/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractCallData.h
 * Author: trungthanh
 *
 * Created on July 24, 2017, 3:14 PM
 */

#ifndef ABSTRACTCALLDATA_H
#define ABSTRACTCALLDATA_H

#include <grpc++/grpc++.h>

class CallProcessorIf{
public:
    virtual ~CallProcessorIf() {};
    virtual void Proceed() = 0;
    CallProcessorIf* getMeBase(){
        return this;
    }
    virtual void Failed() {};
};

template <class TAsyncType>
class AbstractCallData : public CallProcessorIf{
public:
    AbstractCallData(TAsyncType* aService, grpc::ServerCompletionQueue* aCq)
    :_service(aService)
    ,_cq(aCq) 
    ,_context()
    {};
    
    virtual ~AbstractCallData() {};

public:
    virtual AbstractCallData* clone() = 0;
    
    
    template <class DerivedCall> static DerivedCall* startAcceptingCall(TAsyncType* aService, grpc::ServerCompletionQueue* aCq)
    {
        DerivedCall* aCall = new DerivedCall(aService, aCq);
        aCall->Proceed();
        return aCall;
    }
    

protected:
    TAsyncType* _service;
    // The producer-consumer queue where for asynchronous server notifications.
    grpc::ServerCompletionQueue* _cq;

    
    // Context for the rpc, allowing to tweak aspects of it such as the use
    // of compression, authentication, as well as to send metadata back to the
    // client.
    grpc::ServerContext _context;    
    
//    enum TStatus{
//        EStart,
//        EProcessing,
//        ESending,
//        EReceiving,
//        EStreaming, 
//        EFinish,
//    };

};

#endif /* ABSTRACTCALLDATA_H */


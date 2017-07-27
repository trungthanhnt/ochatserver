/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageASyncServer.cpp
 * Author: trungthanh
 * 
 * Created on July 23, 2017, 5:30 PM
 */

#include "MessageASyncServer.h"
#include "ExchangeMessageDataCall.h"
#include <iostream>
using namespace std;

using namespace grpc;

MessageASyncServer::MessageASyncServer(const std::string& svrAddr)
:_serverAddress(svrAddr){
}

MessageASyncServer::MessageASyncServer(const MessageASyncServer& orig) {
}

MessageASyncServer::~MessageASyncServer() {
}

void MessageASyncServer::run()
{

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(_serverAddress, grpc::InsecureServerCredentials());
    // Register "_asyncService" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&_asyncService);
    
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    _cq = builder.AddCompletionQueue();
//    _cqcall = builder.AddCompletionQueue();
    
    // Finally assemble the server.
    _server = builder.BuildAndStart();
    std::cout << "Server listening on " << _serverAddress << std::endl;

    // Proceed to the server's main loop.
    startWaitingAndProcessCalls();
    
}

void MessageASyncServer::startWaitingAndProcessCalls()
{
    //Create calls and Proceed them;
    
            //= ExchangeMessageDataCall::startAcceptingCall<ExchangeMessageDataCall>(this->_asyncService,
            //this->_cq );
    
    ExchangeMessageDataCall* aCall = new ExchangeMessageDataCall(&this->_asyncService, _cq.get() );    
    aCall->Proceed();
    
    while (true)
    {
        bool ok = false;
        void* tag;
//        GPR_ASSERT(_cq->Next(&tag, &ok));
        if (!_cq->Next(&tag,&ok))
        {
            cout<<"Next error "<<endl;
        }
//        GPR_ASSERT(ok);
        if (ok && tag != NULL)
            static_cast<CallProcessorIf*>(tag)->Proceed();
        else {
            cout<<"not ok "<<tag<<endl;
            if (tag != NULL)
                static_cast<CallProcessorIf*>(tag)->Failed();
        }
        
    }
    
}


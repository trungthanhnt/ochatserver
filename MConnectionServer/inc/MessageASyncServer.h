/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageASyncServer.h
 * Author: trungthanh
 *
 * Created on July 23, 2017, 5:30 PM
 */

#ifndef MESSAGEASYNCSERVER_H
#define MESSAGEASYNCSERVER_H

#include <memory>
#include <iostream>
#include <string>
#include <thread>

#include <grpc++/grpc++.h>
#include <grpc/support/log.h>

#include "rpc/messageservice.grpc.pb.h"


class MessageASyncServer {
public:
    MessageASyncServer(const std::string& svrAddr);
    virtual ~MessageASyncServer();
    
public:
    void run();
protected:
    virtual void startWaitingAndProcessCalls();
private:
    MessageASyncServer(const MessageASyncServer& orig);

private:    
    std::string _serverAddress;
    realtime::messageservice::MessageService::AsyncService _asyncService;
    std::unique_ptr<grpc::ServerCompletionQueue> _cq;
//    std::unique_ptr<grpc::ServerCompletionQueue> _cqcall;
    std::unique_ptr<grpc::Server> _server;
 

};

#endif /* MESSAGEASYNCSERVER_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserConnectionsInfo.h
 * Author: trungthanh
 *
 * Created on July 26, 2017, 4:54 PM
 */

#ifndef USERCONNECTIONSINFO_H
#define USERCONNECTIONSINFO_H

#include <set>
#include "rpc/messageservice.pb.h"

class ExchangeMessageDataCall;


class UserConnectionsInfo {
public:
    
    UserConnectionsInfo();
    
    virtual ~UserConnectionsInfo();
    
    void add(ExchangeMessageDataCall* channel) {
        channels.insert(channel);
    }
    
    void remove(ExchangeMessageDataCall* channel)
    {
        channels.erase(channel);
    }
    
    void sendMessage(const realtime::messageservice::S2CMessage& message);
    
private:
    UserConnectionsInfo(const UserConnectionsInfo& orig);

    std::set<ExchangeMessageDataCall* > channels;

};

#endif /* USERCONNECTIONSINFO_H */


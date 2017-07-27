/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UserConnectionsInfo.cpp
 * Author: trungthanh
 * 
 * Created on July 26, 2017, 4:54 PM
 */

#include "UserConnectionsInfo.h"
#include "ExchangeMessageDataCall.h"

UserConnectionsInfo::UserConnectionsInfo() {
}

//UserConnectionsInfo::UserConnectionsInfo(const UserConnectionsInfo& orig) {
//}

UserConnectionsInfo::~UserConnectionsInfo() {
}

void UserConnectionsInfo::sendMessage(const realtime::messageservice::S2CMessage& message)
{
    for (ExchangeMessageDataCall* channel: this->channels)
    {
        channel->SendMessage(message);
    }
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RtMessageModel.cpp
 * Author: trungthanh
 * 
 * Created on July 25, 2017, 1:34 PM
 */

#include "RtMessageModel.h"
#include "ExchangeMessageDataCall.h"
#include "UserConnectionsInfo.h"

//Todo: load from db
uint64_t RtMessageModel::msgIDGen = 1000;
using namespace realtime::messageservice;

RtMessageModel::RtMessageModel() {
}

//RtMessageModel::RtMessageModel(const RtMessageModel& orig) {
//}

RtMessageModel::~RtMessageModel() {
}

std::shared_ptr< UserConnectionsInfo > RtMessageModel::getOrCreateUserCnnInfo(int64_t uid)
{
    std::lock_guard<std::mutex> aLock(mapMutex);
    auto it = userCnnsMap.find(uid);
    if ( it != userCnnsMap.end() )
        return it->second;
    std::shared_ptr< UserConnectionsInfo > aRes (new UserConnectionsInfo);
    userCnnsMap[uid] = aRes;
    return aRes;
}

std::shared_ptr< UserConnectionsInfo > RtMessageModel::getUserCnnInfo(int64_t uid)
{
    std::lock_guard<std::mutex> aLock(mapMutex);
    auto it = userCnnsMap.find(uid);
    if ( it != userCnnsMap.end() )
        return it->second;
    return std::shared_ptr< UserConnectionsInfo >();
}

namespace PrivateInstances{
    static std::shared_ptr<RtMessageModel> _instance (new RtMessageModel() );
}
RtMessageModel* RtMessageModel::instance()
{
    return PrivateInstances::_instance.get();
}

void RtMessageModel::setInstance(RtMessageModel* inst) {
    PrivateInstances::_instance = std::shared_ptr<RtMessageModel>(inst);
        
}

void RtMessageModel::processUserMessage(int64_t uidFrom, realtime::messageservice::C2SMessage& message)
{
    S2CMessage sMsg;
    if (message.has_photomsg() || message.has_txt() )
    {
        
        sMsg.set_msgid( this ->nextMsgID() );
        //sMsg.set_nonceid(message.nonceid() );
        if (message.has_photomsg()) {
            sMsg.mutable_photomsg()->Swap( message.mutable_photomsg() );
            sMsg.set_commonmessage("Photo");
            
        }
        if (message.has_txt() ) {
            sMsg.mutable_txt()->Swap(message.mutable_txt() );
        
            sMsg.set_commonmessage("Text");
        }
        
        if (message.has_base())
            sMsg.mutable_base()->Swap(message.mutable_base() );
        
        if (sMsg.base().userid() >0 )
        {
            //send to user
            this->sendMessage(sMsg.base().userid(), sMsg);
        } 
        else if (sMsg.base().channelid() > 0)
        {
            //Todo: send to channel
            
        }
        else if (sMsg.base().topic()!="" )
        {
            
        }
//        this->sendMessage(message)
    }
}

void RtMessageModel::sendMessage(int64_t uidTo, 
                                 const realtime::messageservice::S2CMessage& message)
{
    auto userCnnInfo = getUserCnnInfo(uidTo);
    if( userCnnInfo.get() )
    {
        userCnnInfo.get()->sendMessage(message);
    }
}

 void RtMessageModel::addUserConnection(int64_t uid , ExchangeMessageDataCall* aCall)
 {
     auto userCnnInfo = getOrCreateUserCnnInfo(uid);
     userCnnInfo->add(aCall);
 }
 
 void RtMessageModel::removeUserConnection(int64_t uid , ExchangeMessageDataCall* aCall)
 {
     auto userCnnInfo = getUserCnnInfo(uid);
     if (userCnnInfo.get())
        userCnnInfo->remove(aCall);
 }
 
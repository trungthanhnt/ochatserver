/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RtMessageModel.h
 * Author: trungthanh
 *
 * Created on July 25, 2017, 1:34 PM
 */

#ifndef RTMESSAGEMODEL_H
#define RTMESSAGEMODEL_H

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include "rpc/messageservice.pb.h"


class ExchangeMessageDataCall;
class UserConnectionsInfo;


//Todo: abstract this class 

class RtMessageModel {
public:
    RtMessageModel();
    
    RtMessageModel(const RtMessageModel& orig);
    
    virtual ~RtMessageModel();
    
    /*Todo: call to SessionService*/
    virtual bool checkSession(const realtime::messageservice::AuthenticateMessage& authMsg)
    {
        return true;
    }
    
    
    virtual void processUserMessage(int64_t uid , realtime::messageservice::C2SMessage& message);
    
    /*Todo: Using Topic management - bigset */
    virtual void subscribe(int64_t uid, const std::string& topic)
    {
        
    }
    
    virtual void unSubscribe(int64_t uid, const std::string& topic)
    {
        
    }
    
    /*Todo: Call to Channel Service */
    virtual int64_t createChannel(int64_t creatorUID, const std::set<int64_t>& memberUIDs)
    {}
    
    virtual void joinChannel(int64_t uid, int64_t channelID)
    {}
    
    virtual void leaveChannel(int64_t uid, int64_t channelID)
    {}
        
    /*Local connection functions */
    virtual void addUserConnection(int64_t uid , ExchangeMessageDataCall* aCall);

    virtual void removeUserConnection(int64_t uid , ExchangeMessageDataCall* aCall);
    
    virtual void sendMessage(int64_t uidTo, const realtime::messageservice::S2CMessage& message);

    virtual void sendMessageToChannel(int64_t uidTo, const realtime::messageservice::S2CMessage& message)
    {}
    
    virtual std::shared_ptr< UserConnectionsInfo > getOrCreateUserCnnInfo(int64_t uid);

    virtual std::shared_ptr< UserConnectionsInfo > getUserCnnInfo(int64_t uid);

    static RtMessageModel* instance();
    
    static void setInstance(RtMessageModel*);
    
    static int64_t nextMsgID(){
        return ++msgIDGen;
    }
    
    static void setIDGetValue(uint64_t aValue) {
        msgIDGen = aValue;
    }
    
private:

    //Todo: using lru or limited cache here 
    std::map<int64_t, std::shared_ptr< UserConnectionsInfo > > userCnnsMap;
    
    std::map<std::string, std::shared_ptr< std::set<int64_t> > > topic2Users;

    std::map<int64_t, std::shared_ptr< std::set<int64_t> > > channel2Users;
    
    std::mutex mapMutex;
    
    static uint64_t msgIDGen;
};

#endif /* RTMESSAGEMODEL_H */


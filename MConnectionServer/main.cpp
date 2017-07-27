/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: trungthanh
 *
 * Created on July 22, 2017, 11:37 PM
 */

#include <cstdlib>
#include <iostream>

#include "MessageASyncServer.h"

using namespace std;

#include "rpc/messageservice.pb.h"
/*
 * 
 */
int main(int argc, char** argv) {
    cout<<"size of realtime::messageservice::LoginMessage "<<sizeof(realtime::messageservice::C2SMessage)<<endl;
    cout<<"size of realtime::messageservice::LoginMessage "<<sizeof(realtime::messageservice::S2CMessage)<<endl;
    cout<<"size of realtime::messageservice::LoginMessage "<<sizeof(realtime::messageservice::LoginRequest)<<endl;
    MessageASyncServer aServer("0.0.0.0:50051");
    aServer.run();
    return 0;
}


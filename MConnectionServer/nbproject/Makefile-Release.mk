#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/rpc/messageservice.grpc.pb.o \
	${OBJECTDIR}/rpc/messageservice.pb.o \
	${OBJECTDIR}/src/AbstractCallData.o \
	${OBJECTDIR}/src/ExchangeMessageDataCall.o \
	${OBJECTDIR}/src/MessageASyncServer.o \
	${OBJECTDIR}/src/RtMessageModel.o \
	${OBJECTDIR}/src/UserConnectionsInfo.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/exchangeMessageClient.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lgrpc++ -lgrpc -lprotobuf -lssl -lcrypto -lz -lpthread -lc -lrt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mconnectionserver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mconnectionserver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mconnectionserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/rpc/messageservice.grpc.pb.o: rpc/messageservice.grpc.pb.cc
	${MKDIR} -p ${OBJECTDIR}/rpc
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rpc/messageservice.grpc.pb.o rpc/messageservice.grpc.pb.cc

${OBJECTDIR}/rpc/messageservice.pb.o: rpc/messageservice.pb.cc
	${MKDIR} -p ${OBJECTDIR}/rpc
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rpc/messageservice.pb.o rpc/messageservice.pb.cc

${OBJECTDIR}/src/AbstractCallData.o: src/AbstractCallData.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AbstractCallData.o src/AbstractCallData.cpp

${OBJECTDIR}/src/ExchangeMessageDataCall.o: src/ExchangeMessageDataCall.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ExchangeMessageDataCall.o src/ExchangeMessageDataCall.cpp

${OBJECTDIR}/src/MessageASyncServer.o: src/MessageASyncServer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MessageASyncServer.o src/MessageASyncServer.cpp

${OBJECTDIR}/src/RtMessageModel.o: src/RtMessageModel.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/RtMessageModel.o src/RtMessageModel.cpp

${OBJECTDIR}/src/UserConnectionsInfo.o: src/UserConnectionsInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UserConnectionsInfo.o src/UserConnectionsInfo.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/exchangeMessageClient.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/exchangeMessageClient.o: tests/exchangeMessageClient.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/exchangeMessageClient.o tests/exchangeMessageClient.cpp


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/rpc/messageservice.grpc.pb_nomain.o: ${OBJECTDIR}/rpc/messageservice.grpc.pb.o rpc/messageservice.grpc.pb.cc 
	${MKDIR} -p ${OBJECTDIR}/rpc
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rpc/messageservice.grpc.pb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rpc/messageservice.grpc.pb_nomain.o rpc/messageservice.grpc.pb.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/rpc/messageservice.grpc.pb.o ${OBJECTDIR}/rpc/messageservice.grpc.pb_nomain.o;\
	fi

${OBJECTDIR}/rpc/messageservice.pb_nomain.o: ${OBJECTDIR}/rpc/messageservice.pb.o rpc/messageservice.pb.cc 
	${MKDIR} -p ${OBJECTDIR}/rpc
	@NMOUTPUT=`${NM} ${OBJECTDIR}/rpc/messageservice.pb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rpc/messageservice.pb_nomain.o rpc/messageservice.pb.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/rpc/messageservice.pb.o ${OBJECTDIR}/rpc/messageservice.pb_nomain.o;\
	fi

${OBJECTDIR}/src/AbstractCallData_nomain.o: ${OBJECTDIR}/src/AbstractCallData.o src/AbstractCallData.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/AbstractCallData.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AbstractCallData_nomain.o src/AbstractCallData.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/AbstractCallData.o ${OBJECTDIR}/src/AbstractCallData_nomain.o;\
	fi

${OBJECTDIR}/src/ExchangeMessageDataCall_nomain.o: ${OBJECTDIR}/src/ExchangeMessageDataCall.o src/ExchangeMessageDataCall.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ExchangeMessageDataCall.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ExchangeMessageDataCall_nomain.o src/ExchangeMessageDataCall.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ExchangeMessageDataCall.o ${OBJECTDIR}/src/ExchangeMessageDataCall_nomain.o;\
	fi

${OBJECTDIR}/src/MessageASyncServer_nomain.o: ${OBJECTDIR}/src/MessageASyncServer.o src/MessageASyncServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/MessageASyncServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MessageASyncServer_nomain.o src/MessageASyncServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/MessageASyncServer.o ${OBJECTDIR}/src/MessageASyncServer_nomain.o;\
	fi

${OBJECTDIR}/src/RtMessageModel_nomain.o: ${OBJECTDIR}/src/RtMessageModel.o src/RtMessageModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/RtMessageModel.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/RtMessageModel_nomain.o src/RtMessageModel.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/RtMessageModel.o ${OBJECTDIR}/src/RtMessageModel_nomain.o;\
	fi

${OBJECTDIR}/src/UserConnectionsInfo_nomain.o: ${OBJECTDIR}/src/UserConnectionsInfo.o src/UserConnectionsInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/UserConnectionsInfo.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -I. -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UserConnectionsInfo_nomain.o src/UserConnectionsInfo.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/UserConnectionsInfo.o ${OBJECTDIR}/src/UserConnectionsInfo_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

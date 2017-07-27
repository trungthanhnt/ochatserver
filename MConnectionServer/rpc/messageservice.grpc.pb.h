// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: messageservice.proto
#ifndef GRPC_messageservice_2eproto__INCLUDED
#define GRPC_messageservice_2eproto__INCLUDED

#include "messageservice.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace realtime {
namespace messageservice {

class LoginService final {
 public:
  static constexpr char const* service_full_name() {
    return "realtime.messageservice.LoginService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status login(::grpc::ClientContext* context, const ::realtime::messageservice::LoginRequest& request, ::realtime::messageservice::LoginReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::realtime::messageservice::LoginReply>> Asynclogin(::grpc::ClientContext* context, const ::realtime::messageservice::LoginRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::realtime::messageservice::LoginReply>>(AsyncloginRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::realtime::messageservice::LoginReply>* AsyncloginRaw(::grpc::ClientContext* context, const ::realtime::messageservice::LoginRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status login(::grpc::ClientContext* context, const ::realtime::messageservice::LoginRequest& request, ::realtime::messageservice::LoginReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::realtime::messageservice::LoginReply>> Asynclogin(::grpc::ClientContext* context, const ::realtime::messageservice::LoginRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::realtime::messageservice::LoginReply>>(AsyncloginRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::realtime::messageservice::LoginReply>* AsyncloginRaw(::grpc::ClientContext* context, const ::realtime::messageservice::LoginRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::RpcMethod rpcmethod_login_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status login(::grpc::ServerContext* context, const ::realtime::messageservice::LoginRequest* request, ::realtime::messageservice::LoginReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_login : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_login() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_login() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status login(::grpc::ServerContext* context, const ::realtime::messageservice::LoginRequest* request, ::realtime::messageservice::LoginReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestlogin(::grpc::ServerContext* context, ::realtime::messageservice::LoginRequest* request, ::grpc::ServerAsyncResponseWriter< ::realtime::messageservice::LoginReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_login<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_login : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_login() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_login() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status login(::grpc::ServerContext* context, const ::realtime::messageservice::LoginRequest* request, ::realtime::messageservice::LoginReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_login : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_login() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::StreamedUnaryHandler< ::realtime::messageservice::LoginRequest, ::realtime::messageservice::LoginReply>(std::bind(&WithStreamedUnaryMethod_login<BaseClass>::Streamedlogin, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_login() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status login(::grpc::ServerContext* context, const ::realtime::messageservice::LoginRequest* request, ::realtime::messageservice::LoginReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedlogin(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::realtime::messageservice::LoginRequest,::realtime::messageservice::LoginReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_login<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_login<Service > StreamedService;
};

class OpenAPIService final {
 public:
  static constexpr char const* service_full_name() {
    return "realtime.messageservice.OpenAPIService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
  private:
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
  };
  typedef Service AsyncService;
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

// The greeting service definition.
class MessageService final {
 public:
  static constexpr char const* service_full_name() {
    return "realtime.messageservice.MessageService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // the first message in the stream must be a message with session 
    //
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>> exchangeMessages(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>>(exchangeMessagesRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>> AsyncexchangeMessages(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>>(AsyncexchangeMessagesRaw(context, cq, tag));
    }
    // exchange single messages
    virtual ::grpc::Status sendSingleMessage(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::realtime::messageservice::S2CMessage* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::realtime::messageservice::S2CMessage>> AsyncsendSingleMessage(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::realtime::messageservice::S2CMessage>>(AsyncsendSingleMessageRaw(context, request, cq));
    }
    // one way stream from server to client 
    std::unique_ptr< ::grpc::ClientReaderInterface< ::realtime::messageservice::S2CMessage>> pollMessages(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::realtime::messageservice::S2CMessage>>(pollMessagesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::realtime::messageservice::S2CMessage>> AsyncpollMessages(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::realtime::messageservice::S2CMessage>>(AsyncpollMessagesRaw(context, request, cq, tag));
    }
    // one way stream from client to server 
    std::unique_ptr< ::grpc::ClientWriterInterface< ::realtime::messageservice::C2SMessage>> pushMessages(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::realtime::messageservice::C2SMessage>>(pushMessagesRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::realtime::messageservice::C2SMessage>> AsyncpushMessages(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::realtime::messageservice::C2SMessage>>(AsyncpushMessagesRaw(context, response, cq, tag));
    }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>* exchangeMessagesRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>* AsyncexchangeMessagesRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::realtime::messageservice::S2CMessage>* AsyncsendSingleMessageRaw(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::realtime::messageservice::S2CMessage>* pollMessagesRaw(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::realtime::messageservice::S2CMessage>* AsyncpollMessagesRaw(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientWriterInterface< ::realtime::messageservice::C2SMessage>* pushMessagesRaw(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::realtime::messageservice::C2SMessage>* AsyncpushMessagesRaw(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>> exchangeMessages(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>>(exchangeMessagesRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>> AsyncexchangeMessages(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>>(AsyncexchangeMessagesRaw(context, cq, tag));
    }
    ::grpc::Status sendSingleMessage(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::realtime::messageservice::S2CMessage* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::realtime::messageservice::S2CMessage>> AsyncsendSingleMessage(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::realtime::messageservice::S2CMessage>>(AsyncsendSingleMessageRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::realtime::messageservice::S2CMessage>> pollMessages(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::realtime::messageservice::S2CMessage>>(pollMessagesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::realtime::messageservice::S2CMessage>> AsyncpollMessages(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::realtime::messageservice::S2CMessage>>(AsyncpollMessagesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientWriter< ::realtime::messageservice::C2SMessage>> pushMessages(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::realtime::messageservice::C2SMessage>>(pushMessagesRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::realtime::messageservice::C2SMessage>> AsyncpushMessages(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::realtime::messageservice::C2SMessage>>(AsyncpushMessagesRaw(context, response, cq, tag));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientReaderWriter< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>* exchangeMessagesRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>* AsyncexchangeMessagesRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncResponseReader< ::realtime::messageservice::S2CMessage>* AsyncsendSingleMessageRaw(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::realtime::messageservice::S2CMessage>* pollMessagesRaw(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request) override;
    ::grpc::ClientAsyncReader< ::realtime::messageservice::S2CMessage>* AsyncpollMessagesRaw(::grpc::ClientContext* context, const ::realtime::messageservice::C2SMessage& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientWriter< ::realtime::messageservice::C2SMessage>* pushMessagesRaw(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response) override;
    ::grpc::ClientAsyncWriter< ::realtime::messageservice::C2SMessage>* AsyncpushMessagesRaw(::grpc::ClientContext* context, ::realtime::messageservice::S2CMessage* response, ::grpc::CompletionQueue* cq, void* tag) override;
    const ::grpc::RpcMethod rpcmethod_exchangeMessages_;
    const ::grpc::RpcMethod rpcmethod_sendSingleMessage_;
    const ::grpc::RpcMethod rpcmethod_pollMessages_;
    const ::grpc::RpcMethod rpcmethod_pushMessages_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // the first message in the stream must be a message with session 
    //
    virtual ::grpc::Status exchangeMessages(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::realtime::messageservice::S2CMessage, ::realtime::messageservice::C2SMessage>* stream);
    // exchange single messages
    virtual ::grpc::Status sendSingleMessage(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::realtime::messageservice::S2CMessage* response);
    // one way stream from server to client 
    virtual ::grpc::Status pollMessages(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::grpc::ServerWriter< ::realtime::messageservice::S2CMessage>* writer);
    // one way stream from client to server 
    virtual ::grpc::Status pushMessages(::grpc::ServerContext* context, ::grpc::ServerReader< ::realtime::messageservice::C2SMessage>* reader, ::realtime::messageservice::S2CMessage* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_exchangeMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_exchangeMessages() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_exchangeMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status exchangeMessages(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::realtime::messageservice::S2CMessage, ::realtime::messageservice::C2SMessage>* stream) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestexchangeMessages(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::realtime::messageservice::S2CMessage, ::realtime::messageservice::C2SMessage>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_sendSingleMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_sendSingleMessage() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_sendSingleMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendSingleMessage(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::realtime::messageservice::S2CMessage* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsendSingleMessage(::grpc::ServerContext* context, ::realtime::messageservice::C2SMessage* request, ::grpc::ServerAsyncResponseWriter< ::realtime::messageservice::S2CMessage>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_pollMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_pollMessages() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_pollMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status pollMessages(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::grpc::ServerWriter< ::realtime::messageservice::S2CMessage>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestpollMessages(::grpc::ServerContext* context, ::realtime::messageservice::C2SMessage* request, ::grpc::ServerAsyncWriter< ::realtime::messageservice::S2CMessage>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(2, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_pushMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_pushMessages() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_pushMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status pushMessages(::grpc::ServerContext* context, ::grpc::ServerReader< ::realtime::messageservice::C2SMessage>* reader, ::realtime::messageservice::S2CMessage* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestpushMessages(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::realtime::messageservice::S2CMessage, ::realtime::messageservice::C2SMessage>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(3, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_exchangeMessages<WithAsyncMethod_sendSingleMessage<WithAsyncMethod_pollMessages<WithAsyncMethod_pushMessages<Service > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_exchangeMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_exchangeMessages() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_exchangeMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status exchangeMessages(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::realtime::messageservice::S2CMessage, ::realtime::messageservice::C2SMessage>* stream) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_sendSingleMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_sendSingleMessage() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_sendSingleMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendSingleMessage(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::realtime::messageservice::S2CMessage* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_pollMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_pollMessages() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_pollMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status pollMessages(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::grpc::ServerWriter< ::realtime::messageservice::S2CMessage>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_pushMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_pushMessages() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_pushMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status pushMessages(::grpc::ServerContext* context, ::grpc::ServerReader< ::realtime::messageservice::C2SMessage>* reader, ::realtime::messageservice::S2CMessage* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_sendSingleMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_sendSingleMessage() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::StreamedUnaryHandler< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>(std::bind(&WithStreamedUnaryMethod_sendSingleMessage<BaseClass>::StreamedsendSingleMessage, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_sendSingleMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status sendSingleMessage(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::realtime::messageservice::S2CMessage* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedsendSingleMessage(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::realtime::messageservice::C2SMessage,::realtime::messageservice::S2CMessage>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_sendSingleMessage<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_pollMessages : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_pollMessages() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::SplitServerStreamingHandler< ::realtime::messageservice::C2SMessage, ::realtime::messageservice::S2CMessage>(std::bind(&WithSplitStreamingMethod_pollMessages<BaseClass>::StreamedpollMessages, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_pollMessages() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status pollMessages(::grpc::ServerContext* context, const ::realtime::messageservice::C2SMessage* request, ::grpc::ServerWriter< ::realtime::messageservice::S2CMessage>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedpollMessages(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::realtime::messageservice::C2SMessage,::realtime::messageservice::S2CMessage>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_pollMessages<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_sendSingleMessage<WithSplitStreamingMethod_pollMessages<Service > > StreamedService;
};

}  // namespace messageservice
}  // namespace realtime


#endif  // GRPC_messageservice_2eproto__INCLUDED
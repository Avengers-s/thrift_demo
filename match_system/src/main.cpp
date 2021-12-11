// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "match_server/Match.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::match_service;

class MatchHandler : virtual public MatchIf {
 public:
  MatchHandler() {
    // Your initialization goes here
  }

  /**
   * user: 添加的用户信息
   * info: 附加信息
   * 在匹配池中添加一个名用户
   * 
   * @param user
   * @param info
   */
  int32_t add_user(const User& user, const std::string& info) {
    // Your implementation goes here
    printf("add_user\n");
    return 0;
  }

  /**
   * user: 删除的用户信息
   * info: 附加信息
   * 从匹配池中删除一名用户
   * 
   * @param user
   * @param info
   */
  int32_t remove_user(const User& user, const std::string& info) {
    // Your implementation goes here
    printf("remove_user\n");
    return 0;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<MatchHandler> handler(new MatchHandler());
  ::std::shared_ptr<TProcessor> processor(new MatchProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}


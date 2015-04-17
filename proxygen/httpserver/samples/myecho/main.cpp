#include <iostream>
#include <unistd.h>
using namespace std;


#include <folly/Memory.h>
#include <folly/Portability.h>
#include <folly/io/async/EventBaseManager.h>

#include <proxygen/httpserver/HTTPServer.h>
#include <proxygen/httpserver/RequestHandlerFactory.h>



using namespace proxygen;

#include <request_handler.h>
#include <server_stat.h>

using folly::EventBase;
using folly::EventBaseManager;
using folly::SocketAddress;

class EchoHandler:public RequestHandlerFactory {

	public:
		void onServerStart() noexcept override {
			d_statPtr.reset(new ServerStat());
		
		}

		void onServerStop() noexcept override {
			d_statPtr.reset();	
		}

		RequestHandler* onRequest(RequestHandler *handler, HTTPMessage *msg) noexcept override {
		   return new  MyRequestHandler(d_statPtr.get());
		}

	private:
		folly::ThreadLocalPtr<ServerStat> d_statPtr;
};



int main(int argc, char **argv) {

	gflags::ParseCommandLineFlags(&argc,&argv,true);
	google::InitGoogleLogging(argv[0]);
	cout<<"This is echo testing"<<endl;
	return 0;
}

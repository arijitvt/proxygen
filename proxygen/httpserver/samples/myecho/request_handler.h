
#ifndef INCLUDE_REQ_HANDLER
#define INCLUDE_REQ_HANDLER

/***
 * @Author : Arijit Chattopadhyay
 ***/


#include <folly/Memory.h>
#include <proxygen/httpserver/RequestHandler.h>

#include <server_stat.h>

using namespace proxygen;

class ResponseHandler;


class MyRequestHandler:public RequestHandler {
	public:
		explicit MyRequestHandler(ServerStat *stat) :stat_(stat) {}
		void onRequest(std::unique_ptr<HTTPMessage> headers) noexcept override {
			stat_->incrementStat();
		}

		void onBody(std::unique_ptr<folly::IOBuf> body) noexcept override;

		void onUpgrade(UpgradeProtocol protocol) noexcept override {
		
		}

		void onEOM() noexcept override;
		void requestComplete() noexcept override;
		void onError(ProxygenError err) noexcept override ;

	private:
		ServerStat *const stat_{nullptr} ;
		std::unique_ptr<folly::IOBuf> body_;

};

#endif

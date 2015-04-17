#include <request_handler.h>

#include <proxygen/httpserver/ResponseBuilder.h>


void MyRequestHandler::onBody(std::unique_ptr<folly::IOBuf> body) noexcept {
	if(body_) {
		body_->prependChain(std::move(body));
	}else {
	 	body_= std::move(body);
	}
}


void MyRequestHandler::onEOM() noexcept {
	ResponseBuilder(downstream_).status(200, "OK")
		.header("Request-Number",
				folly::to<std::string>(stat_->getStat()))
		.body(std::move(body_))
		.sendWithEOM();
}


void MyRequestHandler::requestComplete() noexcept {
	delete this;
}

void MyRequestHandler::onError(ProxygenError err) noexcept {
 	delete this;
}

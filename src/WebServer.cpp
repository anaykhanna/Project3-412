#include "WebServer.h"

WebServer::WebServer(int id)
    : id(id), busy(false), remainingTime(0) {}

bool WebServer::isBusy() const {
    return busy;
}

void WebServer::assign(const Request& r) {
    currentRequest = r;
    remainingTime = r.duration;
    busy = true;
}

void WebServer::tick() {
    if (busy) {
        remainingTime--;
    }
}

std::optional<Request> WebServer::tryFinish() {
    if (busy && remainingTime <= 0) {
        busy = false;
        return currentRequest;
    }
    return std::nullopt;
}

int WebServer::getId() const {
    return id;
}
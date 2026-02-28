#include "RequestQueue.h"

void RequestQueue::push(const Request& r) {
    queue.push(r);
}

void RequestQueue::pop() {
    queue.pop();
}

Request& RequestQueue::front() {
    return queue.front();
}

bool RequestQueue::empty() const {
    return queue.empty();
}

size_t RequestQueue::size() const {
    return queue.size();
}
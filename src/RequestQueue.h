/**
 * @file RequestQueue.h
 * @brief Defines a FIFO queue for managing Request objects.
 *
 * The RequestQueue class wraps a std::queue<Request>
 * and provides basic queue operations for the load balancer.
 */

#pragma once

#include <queue>
#include "Request.h"

/**
 * @class RequestQueue
 * @brief Implements a First-In-First-Out (FIFO) queue of requests.
 *
 * This class provides basic queue operations:
 * - push()
 * - pop()
 * - front()
 * - empty()
 * - size()
 *
 * It is used by the LoadBalancer to manage incoming requests.
 */
class RequestQueue {
private:
    std::queue<Request> queue; ///< Underlying STL queue container

public:

    /**
     * @brief Adds a request to the queue.
     * @param r The request to add.
     */
    void push(const Request& r);

    /**
     * @brief Removes the front request from the queue.
     *
     * Assumes the queue is not empty.
     */
    void pop();

    /**
     * @brief Returns a reference to the front request.
     * @return Reference to the front Request object.
     */
    Request& front();

    /**
     * @brief Checks whether the queue is empty.
     * @return True if empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Returns the number of requests in the queue.
     * @return Current queue size.
     */
    size_t size() const;
};
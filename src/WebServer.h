/**
 * @file WebServer.h
 * @brief Defines the WebServer class which simulates processing web requests.
 *
 * A WebServer processes one request at a time. It tracks:
 * - Whether it is currently busy
 * - Remaining processing time
 * - The request currently being handled
 */

#pragma once

#include "Request.h"
#include <optional>

/**
 * @class WebServer
 * @brief Simulates a single web server.
 *
 * The WebServer processes exactly one Request at a time.
 * Each clock cycle reduces the remaining processing time.
 * When processing completes, the finished request is returned.
 */
class WebServer {
private:
    int id;                               ///< Unique identifier for the server
    bool busy;                            ///< True if server is processing a request
    int remainingTime;                    ///< Remaining clock cycles to finish request
    std::optional<Request> currentRequest;///< Currently assigned request

public:

    /**
     * @brief Constructs a WebServer with a unique ID.
     * @param id Unique identifier for the server.
     */
    WebServer(int id);

    /**
     * @brief Checks whether the server is currently busy.
     * @return True if busy, false otherwise.
     */
    bool isBusy() const;

    /**
     * @brief Assigns a request to the server.
     * @param r The request to process.
     *
     * The server becomes busy and begins processing.
     */
    void assign(const Request& r);

    /**
     * @brief Advances the server by one clock cycle.
     *
     * Decrements remaining processing time if busy.
     */
    void tick();

    /**
     * @brief Checks if the current request has finished.
     * @return Optional<Request> containing finished request if complete.
     *
     * If processing is complete, the server becomes idle.
     */
    std::optional<Request> tryFinish();

    /**
     * @brief Gets the server's unique identifier.
     * @return Server ID.
     */
    int getId() const;
};
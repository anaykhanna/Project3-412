/**
 * @file LoadBalancer.h
 * @brief Defines the LoadBalancer class responsible for managing servers and requests.
 *
 * The LoadBalancer:
 * - Manages a dynamic pool of WebServer instances
 * - Maintains a queue of incoming requests
 * - Generates new requests randomly during simulation
 * - Applies firewall filtering
 * - Dynamically scales servers based on queue thresholds
 * - Tracks performance statistics
 */

#pragma once

#include <vector>
#include "WebServer.h"
#include "RequestQueue.h"
#include "Firewall.h"

/**
 * @class LoadBalancer
 * @brief Simulates a dynamic load balancer.
 *
 * The LoadBalancer distributes incoming requests across
 * multiple web servers. It automatically scales the number
 * of servers to maintain the queue size between:
 *
 * - 50 × number_of_servers  (scale down threshold)
 * - 80 × number_of_servers  (scale up threshold)
 *
 * It also tracks runtime statistics and applies firewall filtering.
 */
class LoadBalancer {
private:
    std::vector<WebServer> servers;   ///< Dynamic pool of active web servers
    RequestQueue requestQueue;        ///< FIFO queue of incoming requests
    int totalCycles;                  ///< Total simulation clock cycles

    int cooldown;                     ///< Remaining cycles before next scaling decision
    int cooldownPeriod;               ///< Wait period between scaling actions

    Firewall firewall;                ///< Firewall for IP blocking

    // Statistics
    int totalGenerated = 0;           ///< Total requests generated during simulation
    int totalProcessed = 0;           ///< Total requests successfully processed
    int totalBlocked = 0;             ///< Total requests blocked by firewall
    int totalScaleUps = 0;            ///< Number of times servers were added
    int totalScaleDowns = 0;          ///< Number of times servers were removed
    int maxQueueSize = 0;             ///< Maximum queue size observed
    long long cumulativeQueueSize = 0;///< Used to compute average queue size

public:

    /**
     * @brief Constructs a LoadBalancer.
     *
     * @param numServers Initial number of web servers.
     * @param cycles Number of clock cycles to simulate.
     */
    LoadBalancer(int numServers, int cycles);

    /**
     * @brief Adds a request to the queue if not blocked.
     *
     * @param r The request to be added.
     */
    void addRequest(const Request& r);

    /**
     * @brief Runs the load balancer simulation.
     *
     * This method:
     * - Simulates clock cycles
     * - Generates random requests
     * - Assigns work to servers
     * - Applies scaling logic
     * - Tracks statistics
     * - Prints final summary
     */
    void run();
};
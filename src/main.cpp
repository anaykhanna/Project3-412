/**
 * @file main.cpp
 * @brief Entry point for the Load Balancer simulation.
 *
 * This program simulates a dynamic load balancer system.
 *
 * Features:
 * - Accepts user input or command-line arguments
 * - Initializes a LoadBalancer instance
 * - Generates an initial full queue (servers × 100 requests)
 * - Runs the simulation for the specified number of clock cycles
 *
 * Usage:
 *   ./loadbalancer <numServers> <totalCycles>
 *
 * If no command-line arguments are provided,
 * the program prompts the user for input.
 */

#include <iostream>
#include <cstdlib>
#include "LoadBalancer.h"
#include "Utils.h"

/**
 * @brief Main driver for the load balancer simulation.
 *
 * @param argc Argument count
 * @param argv Argument vector
 * @return int Exit status code
 */
int main(int argc, char* argv[]) {

    int numServers;
    int totalCycles;

    // Option 1: Command-line arguments
    if (argc == 3) {
        numServers = std::atoi(argv[1]);
        totalCycles = std::atoi(argv[2]);
    }
    else {
        // Option 2: Interactive input
        std::cout << "Enter number of servers: ";
        std::cin >> numServers;

        std::cout << "Enter number of clock cycles: ";
        std::cin >> totalCycles;
    }

    // Create load balancer instance
    LoadBalancer lb(numServers, totalCycles);

    // Generate initial full queue (servers × 100 requests)
    for (int i = 1; i <= numServers * 100; i++) {
        Request r;
        r.id = i;
        r.ip_in = generateRandomIP();
        r.ip_out = generateRandomIP();
        r.duration = generateRandomDuration(5, 20);
        r.jobType = generateRandomJobType();

        lb.addRequest(r);
    }

    // Run simulation
    lb.run();

    return 0;
}
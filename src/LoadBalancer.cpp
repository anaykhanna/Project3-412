#include <iostream>
#include <cstdlib>
#include "LoadBalancer.h"
#include "Utils.h"
bool useColor = true;

#define RESET   (useColor ? "\033[0m"  : "")
#define RED     (useColor ? "\033[31m" : "")
#define GREEN   (useColor ? "\033[32m" : "")
#define YELLOW  (useColor ? "\033[33m" : "")
#define CYAN    (useColor ? "\033[36m" : "")
#define MAGENTA (useColor ? "\033[35m" : "")
LoadBalancer::LoadBalancer(int numServers, int cycles)
    : totalCycles(cycles), cooldown(0), cooldownPeriod(3)
{
    for (int i = 0; i < numServers; i++) {
        servers.emplace_back(i + 1);
    }

    firewall.blockRange(0xC0A80000, 0xC0A8FFFF);
    firewall.blockRange(0x0A000000, 0x0AFFFFFF); 

}

void LoadBalancer::addRequest(const Request& r) {
    if (!firewall.isBlocked(r.ip_in)) {
        requestQueue.push(r);
    }
}

void LoadBalancer::run() {

    std::cout << "Initial Queue Size: "
              << requestQueue.size()
              << "\n\n";

    for (int t = 1; t <= totalCycles; t++) {

        std::cout << "===== Clock Cycle "
                  << t
                  << " =====\n";

        // Random new arrivals
        if (rand() % 100 < 25) {

            static int nextId = 1000;

            Request r;
            r.id = nextId++;
            if (rand() % 100 < 20) {
                r.ip_in = 0x0A000000 + (rand() % 0x00FFFFFF);
            } else {
                r.ip_in = generateRandomIP();
            }           
            r.ip_out = generateRandomIP();
            r.duration = generateRandomDuration(3, 8);
            r.jobType = generateRandomJobType();

            totalGenerated++;

            if (!firewall.isBlocked(r.ip_in)) {

                requestQueue.push(r);

                std::cout << CYAN
                        << "New Request Arrived: "
                        << r.id
                        << " (duration "
                        << r.duration
                        << ")"
                        << RESET
                        << "\n";
            }
            else {

                totalBlocked++;
                std::cout << RED
                        << "Blocked Request from IP "
                        << ipToString(r.ip_in)
                        << RESET
                        << "\n";
            }
        }

        // Assign work
        for (auto& server : servers) {
            if (!server.isBusy() && !requestQueue.empty()) {
                Request r = requestQueue.front();
                requestQueue.pop();
                server.assign(r);

                std::cout << "Server "
                          << server.getId()
                          << " assigned Request "
                          << r.id
                          << "\n";
            }
        }

        // Advance servers
        for (auto& server : servers) {
            server.tick();

            auto finished = server.tryFinish();
            if (finished.has_value()) {

                totalProcessed++;

                std::cout << "Server "
                          << server.getId()
                          << " finished Request "
                          << finished->id
                          << "\n";
            }
        }

        if (cooldown > 0) {
            cooldown--;
        }

        int queueSize = requestQueue.size();
        int serverCount = servers.size();

        cumulativeQueueSize += queueSize;
        if (queueSize > maxQueueSize)
            maxQueueSize = queueSize;

        if (cooldown == 0) {

            if (queueSize > 80 * serverCount) {

                servers.emplace_back(serverCount + 1);
                totalScaleUps++;

                std::cout << GREEN
                        << "Scaling UP → Added Server "
                        << serverCount + 1
                        << RESET
                        << "\n";

                cooldown = cooldownPeriod;
            }

            else if (queueSize < 50 * serverCount && serverCount > 1) {

                if (!servers.back().isBusy()) {

                std::cout << YELLOW
                        << "Scaling DOWN → Removed Server "
                        << serverCount
                        << RESET
                        << "\n";

                    servers.pop_back();
                    totalScaleDowns++;

                    cooldown = cooldownPeriod;
                }
            }
        }

        std::cout << "Queue Size: "
                  << requestQueue.size()
                  << "\n\n";
    }

    double avgQueue = static_cast<double>(cumulativeQueueSize) / totalCycles;

    std::cout << MAGENTA
            << "\n===== Simulation Summary =====\n"
            << RESET;    std::cout << "Total Generated: " << totalGenerated << "\n";
    std::cout << "Total Processed: " << totalProcessed << "\n";
    std::cout << "Total Blocked: " << totalBlocked << "\n";
    std::cout << "Scale Ups: " << totalScaleUps << "\n";
    std::cout << "Scale Downs: " << totalScaleDowns << "\n";
    std::cout << "Max Queue Size: " << maxQueueSize << "\n";
    std::cout << "Average Queue Size: " << avgQueue << "\n";
    std::cout << "Final Server Count: " << servers.size() << "\n";
}
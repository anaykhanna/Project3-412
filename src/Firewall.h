/**
 * @file Firewall.h
 * @brief Defines the Firewall class used to block IP address ranges.
 *
 * The Firewall prevents requests from entering the system
 * if their source IP address falls within a blocked range.
 */

#pragma once

#include <vector>
#include <cstdint>

/**
 * @class Firewall
 * @brief Blocks requests based on IP address ranges.
 *
 * The Firewall stores multiple blocked IP ranges.
 * Each range is defined by a starting and ending IP address.
 * Incoming requests are checked against these ranges.
 */
class Firewall {
private:
    std::vector<std::pair<uint32_t, uint32_t>> blockedRanges;
    ///< List of blocked IP ranges (start, end)

public:

    /**
     * @brief Adds a blocked IP range.
     *
     * @param start Starting IP address (inclusive).
     * @param end Ending IP address (inclusive).
     */
    void blockRange(uint32_t start, uint32_t end);

    /**
     * @brief Checks whether an IP address is blocked.
     *
     * @param ip IP address to check.
     * @return True if the IP falls within any blocked range.
     */
    bool isBlocked(uint32_t ip) const;
};
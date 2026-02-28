#include "Firewall.h"

void Firewall::blockRange(uint32_t start, uint32_t end) {
    blockedRanges.emplace_back(start, end);
}

bool Firewall::isBlocked(uint32_t ip) const {
    for (const auto& range : blockedRanges) {
        if (ip >= range.first && ip <= range.second) {
            return true;
        }
    }
    return false;
}
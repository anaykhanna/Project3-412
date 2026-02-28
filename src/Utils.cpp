#include "Utils.h"
#include <sstream>

std::string ipToString(uint32_t ip) {
    std::ostringstream oss;
    oss  << ((ip >> 24) & 0xFF) << "."
         << ((ip >> 16) & 0xFF) << "."
         << ((ip >> 8) & 0xFF) << "."
         << (ip & 0xFF);
    return oss.str();
}

#include <random>

uint32_t generateRandomIP() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFFFFFF);
    return dist(rng);
}

int generateRandomDuration(int min, int max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

char generateRandomJobType() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1);
    return dist(rng) == 0 ? 'P' : 'S';
}
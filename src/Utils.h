#pragma once
#include <string>
#include <cstdint>

std::string ipToString(uint32_t ip);

uint32_t generateRandomIP();
int generateRandomDuration(int min, int max);
char generateRandomJobType();
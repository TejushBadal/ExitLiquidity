#pragma once
#include <vector>
#include "types.h"

std::vector<Signal> crossover_strategy(const std::vector<double>& short_window, const std::vector<double>& long_window, size_t short_size, size_t long_size);

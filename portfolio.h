#pragma once
#include <vector>
#include "types.h"


std::vector<double> simulate(const std::vector<stock_row>& data, const std::vector<Signal>& decisions, double balance);


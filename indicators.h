#pragma once //prevent header from multiple inclusions with >1 reference
#include <vector>
#include "types.h"

//dont use namespace std in header files

std::vector<double> moving_average(const std::vector<stock_row>& stock_data, size_t window_size);
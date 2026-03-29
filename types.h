#pragma once //always add
#include <string>
#include <vector>

//struct for a single row in the csv
struct stock_row {
    std::string date;
    double close;
    int volume;
    double open;
    double high;
    double low;
};

enum Signal { HOLD, BUY, SELL};
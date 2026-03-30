#pragma once //always add
#include <string>
#include <vector>
#include <map>

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

//type must be defined before using in portfolio
struct position{
    std::string ticker;
    int share_count;
};

struct portfolio{
    double cash_reserve;
    double value;
    std::map<std::string, position> positions;
};


#include <string>

//enum for a single row in the csv
struct stock_row {
    std::string date;
    double close;
    int volume;
    double open;
    double high;
    double low;
};
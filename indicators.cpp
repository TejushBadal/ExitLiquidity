#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "indicators.h"
#include "types.h"

using namespace std;

//takes a vector stock row and an int window_size
//returns a list of doubles same size as data
//represents moving average of closing price each day
vector<double> moving_average(const vector<stock_row>& stock_data, size_t window_size){
    
    vector<double> moving_average_list;
    double current_sum  = 0.0; //current total
    //pointer to keep track of window inside array
    int left = 0;

    //defensive checks on input data
    if (stock_data.empty() || (stock_data.size() < window_size)){
        cerr << "please decrease window size or provide more rows" << endl;
        return moving_average_list;
    }

    if (window_size < 1){
        cerr << "please use a window size greater than 0" << endl;
        return moving_average_list;
    }

    //loop through entire data set with sliding window
    for (size_t i = 0; i < stock_data.size(); i++){

        current_sum += stock_data[i].close;

        //while increasing window size, push 0.0 increase sum, move pointer
        if (i < window_size-1){ //cast to size_t to prevent signed/unsigned issue
            moving_average_list.push_back(0.0);
            continue;
        }

        //calculate current window average
        double current_average = current_sum/window_size;
        moving_average_list.push_back(current_average);

        //update window and pointers
        current_sum -= stock_data[left].close;
        left +=1;

    }

    return moving_average_list;
    
}
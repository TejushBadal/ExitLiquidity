#include <vector>
#include <iostream>
#include "types.h"
#include "strategy.h"

using namespace std;

//takes two vector doubles of long window and short window moving averages
//returns a vector of enum signals of buy sell hold
vector<Signal> crossover_strategy(const vector<double>& short_window, const vector<double>& long_window, size_t short_size, size_t long_size){
    
    vector<Signal> decisions;
    //defensive checks
    if (short_window.empty() || long_window.empty()){
        cerr << "PLEASE INPUT NON-EMPTY MOVING AVERAGE WINDOWS" << endl;
        return decisions;
    }
    if (short_size > long_size){
        cerr << "FIRST MA WINDOW MUST BE SMALLER THAN SECOND" << endl;
        return decisions;
    }
    if (short_window.size() != long_window.size()){
        cerr << "PLEASE ENSURE BOTH MOVING AVERAGES ARE EQUAL LENGTH" << endl;
        return decisions;
    }

    //initial index is 0.0 just hold
    decisions.push_back(HOLD);

    for (size_t i = 1; i < short_window.size(); i++){

        //HOLD while waiting for both MAs to have actual values
        if (short_window[i] == 0.0 || long_window[i] == 0.0 || short_window[i-1] == 0.0 || long_window[i-1] == 0.0){
            decisions.push_back(HOLD);
            continue;
        }

        //BUY == yesterday short below long, now its above
        if (short_window[i-1] <= long_window[i-1] && short_window[i] > long_window[i]){
            decisions.push_back(BUY);
        }
        // SELL == yesterday short above long, now its below
        else if (short_window[i-1] >= long_window[i-1] && short_window[i] < long_window[i]){
            decisions.push_back(SELL);
        }
        else{
            decisions.push_back(HOLD);
        }

        
    }

    return decisions;

}

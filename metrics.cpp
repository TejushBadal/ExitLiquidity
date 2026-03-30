#include <iostream> //input
#include <vector>
#include <string>
#include <algorithm>

#include "types.h"

using namespace std;


void calculate_metrics(const vector<double>& valuations, const vector<Signal>& trades){
    //defensive check
    if (valuations.empty()){
        cerr << "NO VALUATION DATA PROVIDED" << endl;
    }
    //TOTAL RETURN
    double total_return = ((valuations.back() - valuations[0])/valuations[0]) *100;

    //MAXIMUM DRAWDOWN
    double max_value = valuations[0];
    double maximum_drawdown = 0;

    for (size_t i = 1; i < valuations.size(); i++){
        if (valuations[i] > max_value){
            max_value = valuations[i];
        }

        maximum_drawdown = max(max_value - valuations[i], maximum_drawdown);

    }

    //NUMBER OF BUYS
    int total_trades = count(trades.begin(), trades.end(), BUY);

    cout << "TOTAL TRADES: " << total_trades<<endl;
    cout << "TOTAL RETURN IS: " << total_return<<"%"<<endl;
    cout << "MAXIMUM DRAWDOWN IS: " << maximum_drawdown<<"$"<<endl;
}
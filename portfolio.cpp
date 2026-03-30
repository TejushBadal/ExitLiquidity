#include <vector>
#include <iostream>
#include <string>
#include "types.h"
#include "portfolio.h"

using namespace std;

//takes a list of stock rows and list of Signals and starting cash
vector<double> simulate(const vector<stock_row>& data, const vector<Signal>& decisions, double balance){

    vector<double> portfolio_value;
    portfolio my_account;

    //defensive checks
    if (data.empty()){
        cerr << "NO STOCK DATA PROVIDED" << endl;
        return portfolio_value;
    }
    if (decisions.empty()){
        cerr << "NO SIGNALS PROVIDED" << endl;
        return portfolio_value;
    }
    if (balance <= 0){
        cerr << "PORTFOLIO MUST BEGIN WITH POSITIVE CASH BALANCE" << endl;
        return portfolio_value;
    }

    // initialize portfolio
    my_account.cash_reserve = balance;
    my_account.value = balance;


    for (size_t i = 0; i < data.size(); i++){
        double share_price = data[i].close;

        //UPDATE ACCOUNT VALUE EACH DAY
        int shares_held = 0;
        if (my_account.positions.count("AAPL") > 0){ //count returns 1 if key exists else 0
            shares_held = my_account.positions["AAPL"].share_count;
        }
        my_account.value = my_account.cash_reserve + (shares_held * share_price);

        //HOLD -- do nothing

        //BUY (no partial shares)
        if (decisions[i] == BUY){
            //find number of shares
            int number_of_shares = static_cast<int>(my_account.cash_reserve/share_price);
            double cost_to_buy = share_price*number_of_shares;

            //update portfolio: add position to the map (only one for now)
            my_account.cash_reserve -= cost_to_buy;
            my_account.positions["AAPL"] = {"AAPL", number_of_shares};

        }
        else if (decisions[i] == SELL){
            int current_owned_shares = my_account.positions["AAPL"].share_count;
            double sale_value = current_owned_shares*share_price;
            my_account.cash_reserve += sale_value;
            //erase position
            my_account.positions.erase("AAPL");
        }


        portfolio_value.push_back(my_account.value);
    }

    return portfolio_value;

}


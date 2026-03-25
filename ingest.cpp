#include <iostream> //input
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "types.h"

using namespace std;

vector<vector<string>> read_csv(const string& filename){ //& passes a reference to the filename pointer and const promises not to mod it
    vector<vector<string>> data; //2d list
    ifstream file(filename); //input file stream

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN FILE" << filename << endl;
        return data;
    }

    string current_line;
    while (getline(file, current_line)){ //read from file into current line

        vector<string> row; //empty list of strings for this row
        stringstream ss(current_line); //cast current line into a string stream to read chunk by chunk
        string cell; //hold each cell

        while (getline(ss, cell, ',')){ //read from string stream until delimeter then store in cell

            row.push_back(cell);

        }
        data.push_back(row);
    }

    file.close();
    return data;

}
// take the raw csv string rows and parse them into a stock_row type
vector<stock_row> parse_csv(const vector<vector<string>>& data){

    vector<stock_row> parsed_data;

    //defensive programming
    if (data.empty()){
         cerr << "NO DATA TO PARSE" << endl;
         return parsed_data;
    }

    //loop through each row in data, skip header (first row)
    for (size_t i = 1; i < data.size(); i++){ //size_t is max size int unsigned
        // each row is a new stock_row instance that we push onto parsed_data
        stock_row current_row;

        current_row.date = data[i][0];
        current_row.close = stod(data[i][1].substr(1));
        current_row.volume = stoi(data[i][2]);
        current_row.open = stod(data[i][3].substr(1));
        current_row.high = stod(data[i][4].substr(1));
        current_row.low = stod(data[i][5].substr(1));

        parsed_data.push_back(current_row);
    }

    return parsed_data;

}

int main(){

    vector<vector<string>> csv_data = read_csv("dataset/AAPL_5YR.csv");
    //call the parser here

    vector<stock_row> parsed_output = parse_csv(csv_data);

    for (int i = 0; i < 5; i++){
        cout << parsed_output[i].date << endl;
    }

    return 0;
}
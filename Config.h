#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Config{
    private:
    string file;
    int max_path_length;
    int max_input;

    public:
    Config(string);
    void readFile();

    int getMaxPathLength(){
        return this->max_path_length;
    }
    int getMaxInput(){
        return this->max_input;
    }
};

Config::Config(string file){
    this->file = file;
    try
    {
        readFile();
    }
    catch(...)
    {
        cout << "Config file can not read" << endl;
    }
    
}

void Config::readFile(){

    fstream filein;
    filein.open(file, ios::in);

    string line, column;
    vector<string> row;

    int row_no = 1;

    //read line by line
    while (getline(filein, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, column, ' ')) {
            row.push_back(column);
		}
        if(row_no==1){
            // cout << "row 1: " << row[0] << " " << row[1] << endl;
            this->max_path_length = stoi(row[1]);
        }
        else if(row_no==2){
            // cout << "row 2: " << row[0] << " " << row[1] << endl;
            this->max_input = stoi(row[1]);
        }
        row_no++;       
    }
}
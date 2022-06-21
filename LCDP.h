#pragma once
#include <iostream>
#include <fstream>
#include "Path.h"

using namespace std;


//longest common directory path
class LCDP{
    private:
    string input_file;
    int input_number;
    vector<Path> inputs;
    string longest_common;

    public:
    LCDP(string);
    void findLongestCommon();
    void readInputFile();

};

LCDP::LCDP(string input_file){
    this->input_file = input_file;
    readInputFile();
}

void LCDP::readInputFile(){
    fstream filein;
    filein.open(input_file, ios::in);

    string line;
    int row_no = 0;

    //read line by line
    while (getline(filein, line)) {
        cout << line << endl;
        Path path(line);
        inputs.push_back(path);
        row_no++;       
    }
    this->input_number = row_no;
    cout << "input number: " << row_no;
}

void LCDP::findLongestCommon(){

}
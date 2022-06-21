#pragma once
#include <iostream>
#include <fstream>
#include "Path.h"
#include "Config.h"

using namespace std;


//longest common directory path
class DirectoryManager{
    private:
    string input_file;
    int input_number;
    vector<Path> inputs;
    string longest_common;
    vector<string> vec_longest_common;

    public:
    DirectoryManager(string, Config);
    void findLongestCommon();
    void readInputFile();
    void writeOutputFile(string);

};

DirectoryManager::DirectoryManager(string input_file, Config config){
    this->input_file = input_file;
    try
    {
        readInputFile();
        if (input_number > config.getMaxInput())
        {
            throw 505;
        }
    }
    catch(...)
    {
        cout << "Input number is oversize" << endl;
    }
}

//read input paths from input file
void DirectoryManager::readInputFile(){
    fstream filein;
    filein.open(input_file, ios::in);

    string line;
    int row_no = 0;

    //read line by line
    while (getline(filein, line)) {
        //create Path object each line from input file
        Path path(line);
        inputs.push_back(path); //push inputs vector
        row_no++;       
    }
    this->input_number = row_no;
}

void DirectoryManager::findLongestCommon(){
    bool same = true;
    int element = 0;

    //Comparing other elements over the Path object, which is the first element in the inputs vector.
    while (same){
        if (inputs[0].getLenVector() <= element){
            break;
        }
        //The element to be compared is assigned temp.
        string temp = inputs[0].vector_real_path[element];
        //The same elements of other inputs are iterated and compared. If different, the loop break
        for (int i = 1; i < input_number; i++)
        {
            //If the length of the iterated Path object is less than the element or its value is not the same as the temp
            if (inputs[i].getLenVector() <= element || inputs[i].vector_real_path[element] != temp)
            {
                same = false;
                break;
            }
        }
        //If all elements are the same push
        if (same){
           vec_longest_common.push_back(temp);
        }
        element++;
    }

    cout << "Longest Common Directory Path: " << endl;
    for (auto x : vec_longest_common) {
        longest_common += "/" + x;
    }
    if (longest_common == ""){
        this->longest_common = "/";
    }
    cout << longest_common;

    writeOutputFile("output.txt");
    
}

//write final result to ouput file
void DirectoryManager::writeOutputFile(string output_file){
    ofstream output;
    output.open (output_file);
    output << longest_common;
    output.close();
}
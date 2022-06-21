#include <iostream>
#include <vector> 
#include "Path.h"
#include "Config.h"
#include "LCDP.h"

using namespace std;


int main(int argc, char *argv[]){
    string input_file = argv[1];

    /*
    Path p1("/abc/a/../b/../c/../x/../../");
    //cout << p1.getRealPath();

    vector<string> v = p1.getVectorRealPath();
    cout << "-----" << endl;
    for (auto it : v) {
        cout << it << endl;
    }
    cout << "len: " << p1.getLenVector() << endl;

    Config config("config.txt");
    cout << "max len: " << config.getMaxPathLength() << endl;
    cout << "max input: " << config.getMaxInput() << endl;
    */
   LCDP a(input_file);


    return 0;
}
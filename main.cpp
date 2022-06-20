#include <iostream>
#include <vector> 
#include "Path.h"
#include "Config.h"

using namespace std;



int main(){

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

    return 0;
}
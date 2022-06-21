#include <iostream>
#include <vector> 
#include "Path.h"
#include "Config.h"
#include "DirectoryManager.h"

using namespace std;


int main(int argc, char *argv[]){
    string input_file = argv[1];

    Config config("config.txt");

    DirectoryManager PathManager(input_file, config);
    PathManager.findLongestCommon();

    return 0;
}
#pragma once
#include <iostream>
#include <vector> 

using namespace std;

class Path{
    private:
    string original_path;
    string real_path; 
    int len_vector;

    public:
    vector<string> vector_real_path;

    Path(string);
    vector<string> findRealPath(string);


    string getRealPath(){
        return real_path;
    }
    string getOriginalPath(){
        return original_path;
    }
    vector<string> getVectorRealPath(){
        return vector_real_path;
    }
    int getLenVector(){
        return len_vector;
    }

};

Path::Path(string path){
    this->original_path = path;
    this->vector_real_path.clear();
    this->len_vector = 0;

    try{
        //this->real_path = findRealPath(this->original_path);
        this->vector_real_path = findRealPath(this->original_path);
    }
    catch(...){
        cout << "Real Path not examined." << endl;
    } 
    
}

//finding absolute path(".. , ." operators are performed and the latest version of the path is found.)
vector<string> Path::findRealPath(string path){

    vector<string> v;

    //Return root if path doesn't start with '/' .
    if(path[0] != '/'){
        this->real_path = "/";
        return v;
    }

    int len_path = path.length();
    string absolute_path;
    string directory_command;

    for (int i = 0; i < len_path; i++) {
        directory_command.clear();

        // command between 2 '/' assigned to directory_command
        while (i < len_path && path[i] != '/') {
            directory_command += path[i];
            i++;
        }
 
        // if command is "..", pop last element from vector, go previous directory.
        if (directory_command == "..") {
            if (!v.empty()){
                v.pop_back();
                this->len_vector -= 1;
            }
        }
        // if command is "." dont do anything
        else if (directory_command == "." || directory_command == "") {
            continue;
        }
        // if command is directory name, push to vector
        else {
            v.push_back(directory_command);
            this->len_vector += 1;
        }
    }

    // iterate vector assign string format with /
    for (auto x : v) {
        //cout << "vector: " << x << endl;
        absolute_path += "/" + x;
    }
 
    // vector is empty
    if (absolute_path == ""){
        //cout << "vector empty " << endl;
        this->real_path = "/";
        return v;
    }

    this->real_path = absolute_path;
    return v;
}
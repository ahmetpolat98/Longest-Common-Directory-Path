Compile: g++ -std=c++11 main.cpp -o main
Run: ./main <inputfile>
example: ./main inputs/input1.txt


-Get input paths from inputs.txt file. Output is written to output.txt file.

Problem description:
    • Find the longest common directory path between given paths
    • Inputs are 2 or more string representing a UNIX path
    • The output will be a string representing the longest common
    path between input paths
Assumptions:
    • Two dots (“..”) indicates parent directory
    • One dot (“.”) represents the current directory
    • More than two leading slashes (“////”) is treated as a single
    slash (“/”)
    • Input paths contains only directories
    • All paths are absolute paths, if an input path does not start
    with “/”, you can return the root path “/”
    • All input paths are valid
    • Maximum path length is 1024
    • Maximum number of input path is 10
    
    
    
Example input:
“/a/b/c/s”
“/a/b/c/f/e”
“/a/b/c/f/e/g”
Expected output:
“/a/b/c”

Example input:
“”
“/c/d”
Expected output:
“/”

Example input:
“/abcd/efg”
“abcd/efg/jkl”
Expected output:
“/”

Example input:
“/a/b”
“/a/././././b”
Expected output:
“/a/b”

Example input:
“/a/b”
“/a/////b”
Expected output:
“/a/b”

Example input:
“/a/b/../../c/d/f”
“/c/d”
“/c/d/h/j”
Expected output:
“/c/d”

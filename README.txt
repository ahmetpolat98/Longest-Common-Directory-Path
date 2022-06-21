Compile: g++ -std=c++11 -Wall -Werror main.cpp -o main
Run: ./main <inputfile>
example: ./main inputs/input1.txt


-Get input paths from inputs.txt file. Settings are made from config.txt file. Output written to output.txt file.

-Analysis of Algorithm:
    -First, I find the realPath of the paths given as input. I apply operators like ".. , . ", and get the final version of the path.
    -
    findRealPath():
        - n: number of input paths
        l: length of input paths
        Time Complexity: O(n*l)

        -Space Complexity: n*l

    -I collected the paths in a vector. I iterate through all Paths as long as the shortest path length. 
    -When there is a different path, I finished the longest common loop and output the result.
    findLongestCommon():
        n: number of input paths
        m: Minimum path length in input paths
        Time Complexity: O(n*m)

        -Space Complexity: n*m

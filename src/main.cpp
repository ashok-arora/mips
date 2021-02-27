/*
 * 1. read file [done]
 * 2. execute line by line
    ** list of accepted tokens
 * 3. print output to file
 * 4. point out error
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <cassert>


int main(int argc, char **argv){
    if (argc < 2){
        std::cout << "Expected file as first argument. None found." << std::endl;
        return -1;
    }
    std::string text;
    std::ifstream fileName(argv[1]);

    while(getline(fileName, text)){
        std::cout << text << std::endl;
    }

    return 0;
}
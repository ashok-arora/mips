/*
 * 1. read file [done]
 * 2. execute line by line
    ** list of accepted tokens
 * 3. print output to file
 * 4. point out error
 */

#include <iostream>
#include <fstream>
// #include <sstream>
#include "tokens.hpp"
#include "registers.hpp"
#include <limits>

int main(int argc, char **argv){
    if (argc < 2){
        std::cout << "Expected file as first argument. None found." << std::endl;
        return -1;
    }
    std::string text;
    std::ifstream fileName(argv[1]);
    while(fileName >> text){
        // std::cout << text << "\n";
        // get just the first word of each line and ignore the rest
        // fileName.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(tokens.find(text) != tokens.end()) {
            std::cout << "Acceptable token: " << text << std::endl;
        }
        else if (unsupported.find(text) != unsupported.end()){
            std::cout << "Unsupported token: " << text << std::endl;
        }
    }
    if(registers.find("ra")!= registers.end()){
        std::cout << "Currently, register $" <<registers.find("ra")->first << " has value " << registers.find("ra")->second << std::endl;
    }

    return 0;
}
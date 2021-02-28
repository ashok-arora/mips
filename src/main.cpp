/*
 * 1. read file [done]
 * 2. execute line by line
    ** list of accepted tokens
 * 3. print output to file [done]
 * 4. point out error
 */

#include <iostream>
#include <fstream>
// #include <sstream>
#include "tokens.hpp"
#include "registers.hpp"
#include <limits>
#include <algorithm>

int main(int argc, char **argv){
    std::filebuf fileBuffer;
    std::ostream output(&fileBuffer);
    if (argc < 2){
        std::cout << "[Error] Expected input file as first argument. None found." << std::endl;
        return -1;
    }
    else if (argc < 3){
        std::cout << "[Warning] Expected output file as second argument! None found. Defaulting to `./build/output.txt`" << std::endl;
        fileBuffer.open("./build/output.txt", std::ios::out);
    }

    fileBuffer.open(argv[2], std::ios::out);
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
    std::vector<std::pair<std::string, int>>::iterator findIt = std::find_if(registers.begin(), registers.end(), CompareFirst("ra"));
    if(findIt != registers.end()) {
        std::cout << "Currently, register $" << findIt->first << " has value " << findIt->second << std::endl;
    } else {
        std::cout << "Register $ra not found. " <<std::endl;
    }

    std::vector<std::pair<std::string, int>>::iterator iter;
    for (iter = registers.begin() ; iter != registers.end() ; iter++){
        output << iter->first << " = " << iter->second << std::endl;
    }

    return 0;
}
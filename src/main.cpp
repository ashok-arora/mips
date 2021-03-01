/*
 * 1. read file [done]
 * 2. execute line by line
    ** list of accepted tokens
 * 3. print output to file [done]
 * 4. point out error [done]
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "tokens.hpp"
#include "registers.hpp"
//#include <limits>
#include <algorithm>

int main(int argc, char **argv){
    std::filebuf fileBuffer;
    std::ostream output(&fileBuffer);
    if (argc < 2){
        std::cout << "[Error] Expected input file as first argument. None found." << std::endl;
        return -1;
    }
    if (argc < 3){
        std::cout << "[Warning] Expected output file as second argument! None found. Defaulting to `./build/output.txt`" << std::endl;
        fileBuffer.open("./build/output.txt", std::ios::out);
    } else {
        fileBuffer.open(argv[2], std::ios::out);
    }

    std::string text;
    std::ifstream fileName(argv[1]);
    while(getline(fileName, text)){
        std::istringstream ss(text);
        std::string token;
        ss >> token;
        if ( token == "#" ){
            std::cout << "[Debug] Comment: " << text << std::endl;
            continue;
        }
        // TODO: getline and split by space
        // std::cout << text << "\n";
        // get just the first word of each line and ignore the rest
        // fileName.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (tokens.find(token) != tokens.end()) {
            std::cout << "[Debug] Acceptable token: " << token << std::endl;
            if (token == "addi"){
                std::string rs, rd;
                int imm;
                ss >> rs >> rd >> imm;
                rs.pop_back();
                rd.pop_back();
                std::cout << "[Debug] " << rs << " " << rd << " " << imm << std::endl;
                std::vector<std::pair<std::string, int>>::iterator find_rs, find_rd;
                find_rs = std::find_if(registers.begin(), registers.end(), CompareFirst(rs));
                find_rd = std::find_if(registers.begin(), registers.end(), CompareFirst(rd));

                if(find_rs != registers.end()) {
                    std::cout << "[Debug] Currently, register " << find_rs->first << " has value " << find_rs->second << std::endl;
                } else {
                    std::cout << "[Debug] Register " << rs << " not found. " <<std::endl;
                }
                // std::cout << find_rs->second << " " << find_rd->second << " " << imm;
                find_rs->second = find_rd->second + imm;
            }

        }
            // TODO: action to take when token is found
            // each token has a certain number of arguments with it and performs a specific task.
        else if (unsupported.find(token) != unsupported.end()) {
            std::cout << "[Warning] Unsupported token: " << token << " will not be executed." << std::endl;
        } else {
            std::cout << "[Error] Cannot parse line: " << text << std::endl;
        }

    }
//    std::vector<std::pair<std::string, int>>::iterator findIt;
//    findIt = std::find_if(registers.begin(), registers.end(), CompareFirst("ra"));
//    if(findIt != registers.end()) {
//        std::cout << "Currently, register $" << findIt->first << " has value " << findIt->second << std::endl;
//    } else {
//        std::cout << "Register $ra not found. " <<std::endl;
//    }

    std::vector<std::pair<std::string, int>>::iterator iter;
    for (iter = registers.begin() ; iter != registers.end() ; iter++){
        output << iter->first << " = " << iter->second << std::endl;
    }
    std::cout << "[Debug] Output saved to file." << std::endl;
    return 0;
}


// input
// parse
// execute
// output
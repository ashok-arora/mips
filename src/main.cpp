#include <iostream>
#include <fstream>
#include <sstream>
#include "tokens.hpp"
#include "registers.hpp"
#include "Logger.hpp"
#include <algorithm>
#include <cstring>

int main(int argc, char **argv){
    std::filebuf fileBuffer;
    std::ostream output(&fileBuffer);
    if (argc < 2){
        if (Log >= Error) {
            std::cout << "[Error] Expected input file as first argument. None found." << std::endl;
            return -1;
        }
    }
    if (argc < 3){
        if (Log >= Warning) {
            std::cout
                    << "[Warning] Expected output file as second argument! None found. Defaulting to `./build/output.txt`"
                    << std::endl;
        }
        fileBuffer.open("./build/output.txt", std::ios::out);
    } else {
        fileBuffer.open(argv[2], std::ios::out);
    }

    if (argc < 4){
        std::cout << "[Warning] No logging level specified. Defaulting to None.";
    } else {
        Log = select(argv[3]);
    }
    std::string text;
    std::ifstream fileName(argv[1]);
    while(getline(fileName, text)){
        std::istringstream ss(text);
        std::string token;
        ss >> token;
        if ( token == "#" ){
            if (Log >= Debug) {
                std::cout << "[Debug] Comment: " << text << std::endl;
            }
            continue;
        }

        if (tokens.find(token) != tokens.end()) {
            if (Log >= Debug) {
                std::cout << "[Debug] Acceptable token: " << token << std::endl;
            }
            if (token == "addi"){
                std::string rs, rd;
                int imm;
                ss >> rs >> rd >> imm;
                rs.pop_back();
                rd.pop_back();
                if (Log >= Debug) {
                    std::cout << "[Debug] " << rs << " " << rd << " " << imm << std::endl;
                }
                std::vector<std::pair<std::string, int>>::iterator find_rs, find_rd;
                find_rs = std::find_if(registers.begin(), registers.end(), CompareFirst(rs));
                find_rd = std::find_if(registers.begin(), registers.end(), CompareFirst(rd));

                if (Log >= Debug) {
                    if (find_rs != registers.end()) {
                        std::cout << "[Debug] Currently, register " << find_rs->first << " has value "
                                  << find_rs->second << std::endl;
                    } else {
                        std::cout << "[Debug] Register " << rs << " not found. " << std::endl;
                    }
                }
                find_rs->second = find_rd->second + imm;
            }

        }

        if (Log >= Warning) {
            if (unsupported.find(token) != unsupported.end()) {
                std::cout << "[Warning] Unsupported token: " << token << " will not be executed." << std::endl;
            } else {
                std::cout << "[Error] Cannot parse line: " << text << std::endl;
            }
        }
    }

    std::vector<std::pair<std::string, int>>::iterator iter;
    for (iter = registers.begin() ; iter != registers.end() ; iter++){
        output << iter->first << " = " << iter->second << std::endl;
    }
    if (Log >= Debug) {
        std::cout << "[Debug] Output saved to file." << std::endl;
    }
    return 0;
}
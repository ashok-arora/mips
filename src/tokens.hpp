//
// Created by ashok on 2/28/21.
//

#ifndef MIPS_TOKENS_HPP
#define MIPS_TOKENS_HPP

#include <unordered_set>

class token{
private:
    std::string name;
    int argCount;
public:
    token(std::string n, const int &aC) : name(std::move(n)), argCount(aC){}
};
std::unordered_set <std::string> tokens {
        "addi"
};

std::unordered_set <std::string> unsupported {
        "add",
        "addiu",
        "and",
        "andi",
        "beq",
        "bne",
};

#endif //MIPS_TOKENS_HPP

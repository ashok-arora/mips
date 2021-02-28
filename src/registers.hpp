//
// Created by ashok on 2/28/21.
//

#ifndef MIPS_REGISTERS_HPP
#define MIPS_REGISTERS_HPP

#include <unordered_map>
#include <vector>

std::vector <std::pair<std::string, int>> registers {
            {"zero", 0},
            {"at", 0},
            {"v0", 0},
            {"v1", 0},
            {"a0", 0},
            {"a1", 0},
            {"a2", 0},
            {"a3", 0},
            {"t0", 0},
            {"t1", 0},
            {"t2", 0},
            {"t3", 0},
            {"t4", 0},
            {"t5", 0},
            {"t6", 0},
            {"s0", 0},
            {"s1", 0},
            {"s2", 0},
            {"s3", 0},
            {"s4", 0},
            {"s5", 0},
            {"s6", 0},
            {"s7", 0},
            {"t8", 0},
            {"t9", 0},
            {"k0", 0},
            {"k1", 0},
            {"gp", 0},
            {"sp", 0},
            {"fp", 0},
            {"ra", 0},
};

struct CompareFirst {
    CompareFirst(std::string val) : val_(val) {}
    bool operator()(const std::pair<std::string,int>& elem) const {
        return val_ == elem.first;
    }
private:
    std::string val_;
};

#endif //MIPS_REGISTERS_HPP

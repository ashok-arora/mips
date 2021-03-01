//
// Created by ashok on 3/1/21.
//

#ifndef MIPS_LOGGER_HPP
#define MIPS_LOGGER_HPP

#include <cstring>

enum LogLevel {
    None,
    Debug,
    Warning,
    Error,
    All
} Log = None;

enum LogLevel select(char *arg) {
    char *options[] = {"None", "Debug", "Warning", "Error", "All"};
    for (int i = 0; i < 5; i++) {
        if (!strcmp(options[i], arg)) {
            return static_cast<LogLevel>(i);
        }
    }
    return None;
}

#endif //MIPS_LOGGER_HPP

/**
 *
 */
#ifndef PROBLBAC_5_H
#define PROBLBAC_5_H

#include <iostream>
#include <cstring>

bool reverse(char *str) {
    size_t length = strlen(str);
    if (length % 2 == 1) {
        char *nonReversed = str;
        std::reverse(str, str + length);
        if (strcmp(nonReversed, str) != 0) return true;
    }
    return false;
}

void solve_5() {
    std::string result;
    char *str = new char[2048];
    std::cin.get(str, 2048);

    bool modified = false;
    for (char *it = strtok(str, " "); it != nullptr; it = strtok(nullptr, " ")) {
        if (reverse(it)) modified = true;
        result = result.append(it).append(" ");
    }
    std::cout << (modified ? result : "nu exista");
}

#endif


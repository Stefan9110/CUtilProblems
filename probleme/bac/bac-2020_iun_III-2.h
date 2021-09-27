#ifndef PROBLBAC_BAC_2020_IUN_III_2_H
#define PROBLBAC_BAC_2020_IUN_III_2_H

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

void solve() {
    std::string result;
    char *str = new char[2048];
    std::cin.get(str, 2048);

    bool modified = false;
    for (char *it = strtok_s(str, " "); it != nullptr; it = strtok_s(nullptr, " ")) {
        if (reverse(it)) modified = true;
        result = result.append(it).append(" ");
    }
    std::cout << (modified ? result : "nu exista");
}

#endif


#ifndef PROBLBAC_GREEDY_9_H
#define PROBLBAC_GREEDY_9_H
#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-9/"
#define MAX_POWER 9

#include "utils/FileAPI.h"
#include "utils/Arrays.h"
#include <cstring>

int get10Power(int value) {
    return (int) to_string(value).length() - 1;
}

int findSearchedPower(int searched_index, const int *counter) {
    int result = MAX_POWER;
    for (; searched_index >= 0; searched_index -= counter[result - 1]) result--;
    return result - 1;
}

static int quick_pow10(int n) {
    static int pow10[10] = {
            1, 10, 100, 1000, 10000,
            100000, 1000000, 10000000, 100000000, 1000000000
    };
    return pow10[n];
}

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    auto searched_index = readFromFile<int>();

    auto *counter = emptyArray<int>(MAX_POWER);
    while (!isFileEmpty()) counter[get10Power(readFromFile<int>())]++;

    int power = findSearchedPower(searched_index, counter) - 1;
    writeToFile(*new string((power < 1 ? "Nu exista" : to_string((quick_pow10(power))))));
}

#endif

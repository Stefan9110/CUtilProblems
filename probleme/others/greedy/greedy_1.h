#ifndef PROBLBAC_GREEDY_1_H
#define PROBLBAC_GREEDY_1_H

#include "utils/FileAPI.h"
#include "utils/Arrays.h"

#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-1/"

bool isValid(int num, const int *minValues) {
    return num < minValues[!(num % 2)];
}

bool isArrayValid(int *arr, size_t length, int *minValues) {
    for (int i = 0; i < length; i++) if (!isValid(arr[i], minValues)) return false;
    return true;
}

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    auto length = readFromFile<size_t>();
    auto *arr = readArrayOfSize<int>(length, file_in);
    int minValues[2] = {107, 107};

    for (int i = 0; i < length; i++) {
        auto val = readFromFile<int>();
        if (minValues[val % 2] > val) minValues[val % 2] = val;
    }

    writeToFile((isArrayValid(arr, length, minValues) ? "DA" : "NU"));
}

#endif

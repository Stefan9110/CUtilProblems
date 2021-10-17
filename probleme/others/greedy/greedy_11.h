#ifndef PROBLBAC_GREEDY_11_H
#define PROBLBAC_GREEDY_11_H
#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-11/"

#include "utils/FileAPI.h"
#include "utils/Arrays.h"

int findResult(int *arr, size_t length) {
    if (arr[length - 1] == arr[0]) return -1;
    for (int i = arr[length - 2]; i >= 0; i--) if (arr[i] < arr[length - 1]) return arr[i];
    return -1;
}

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    auto length = readFromFile<size_t>() / 2 + 1;
    auto *arr = readArrayOfSize<int>(length, file_in);
    int result = findResult(arr, length);
    writeToFile(*new string((result == -1 ? "Nu exista" : to_string(result))));
}

#endif

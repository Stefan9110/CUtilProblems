#ifndef PROBLBAC_PBINFO_91_H
#define PROBLBAC_PBINFO_91_H
#define FILE_NAME "masini"

#include "utils/Arrays.h"
#include "utils/FileAPI.h"
#include <algorithm>

unsigned short maxCount(const unsigned short *arr, size_t length, unsigned short max_time) {
    unsigned short i, consumedTime = 0;
    for (i = 0; i < length && consumedTime + arr[i] < max_time; i++) consumedTime += arr[i];
    return i;
}

void solve() {
    setInputFolder(R"(C:\Users\danie\CUtilProblems\input-files\pbinfo_91\)");
    initialiseFiles(FILE_NAME);

    auto length = readFromFile<size_t>();
    auto max_time = readFromFile<short>();

    auto *arr = readArrayOfSize<unsigned short>(length, file_in);
    std::sort(arr, arr + length);
    writeToFile(maxCount(arr, length, max_time));
}

#endif

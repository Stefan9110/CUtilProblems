//
// Created by dmihn on 10/17/2021.
//

#ifndef PROBLBAC_GREEDY_10_H
#define PROBLBAC_GREEDY_10_H

#include "utils/FileAPI.h"
#include "utils/Arrays.h"
#include <algorithm>
#define FILE_NAME "bac"
#define CONTENT_ROOT "C:\\Users\\dmihn\\CLionProjects\\CUtilProblems\\input-files\\greedy\\greedy-10\\"

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);
    size_t n;
    auto *arr = readArray<int>(n, file_in);
    sort(arr, arr + n / 2);
    int max = -1;
    for (int i = n / 2; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (arr[n / 2 - 1] <= max) {
        writeToFile("Nu exista");
    } else {
        for (int i = 0; i < n / 2; i++) {
            if (arr[i] > max) {
                writeToFile(arr[i]);
                break;
            }
        }
    }
}


#endif //PROBLBAC_GREEDY_10_H

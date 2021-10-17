#ifndef PROBLBAC_GREEDY_6_H
#define PROBLBAC_GREEDY_6_H
#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-6/"

#include "utils/FileAPI.h"
#include "utils/Arrays.h"

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    auto *used = emptyArray<bool>(103);
    short min = 103, max = -1;

    while (!isFileEmpty()) {
        auto num = readFromFile<short>();
        if (num < min) min = num;
        if (num > max) max = num;
        used[num] = true;
    }

    std::string result;
    bool searching_close = false;
    for (int i = min; i <= max; i++) {
        if (!used[i] || (!searching_close && used[i + 1])) continue;
        searching_close = !searching_close;
        result.append(to_string(i)).append(" ");
    }
    writeToFile(result);
}

#endif

#ifndef PROBLBAC_GREEDY_4_H
#define PROBLBAC_GREEDY_4_H
#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-4/"

#include "utils/FileAPI.h"
#include "utils/Arrays.h"

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    auto max_length = readFromFile<size_t>();
    bool *used = emptyArray<bool>(max_length + 1);

    while (!isFileEmpty()) used[readFromFile<int>()] = true;

    std::string result;
    for (int i = 1; i <= max_length; i++) if (!used[i]) result.append(to_string(i)).append(" ");
    writeToFile(result);
}

#endif

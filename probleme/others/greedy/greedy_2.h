#ifndef PROBLBAC_GREEDY_2_H
#define PROBLBAC_GREEDY_2_H
#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-2/"

#include "utils/FileAPI.h"

bool set_to_valid[106];

bool checkForValid(int value, size_t index, int &max, int previous) {
    if (value <= max || (previous != value || set_to_valid[index - 1])) {
        max = value;
        set_to_valid[index] = true;
        return true;
    }
    return false;
}

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    int currentMax = -1, previous = -1;
    std::string result;

    for (size_t index = 0; !isFileEmpty(); index++) {
        auto indexedNumber = readFromFile<int>();
        if (checkForValid(indexedNumber, index, currentMax, previous))
            result.append(to_string(indexedNumber)).append(" ");
        previous = indexedNumber;
    }
    writeToFile(result);
}

#endif

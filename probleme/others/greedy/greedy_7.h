#ifndef PROBLBAC_GREEDY_7_H
#define PROBLBAC_GREEDY_7_H
#define FILE_NAME "bac"
#define CONTENT_ROOT "/home/stefan911/CLionProjects/CUtilProblems/input-files/greedy/greedy-7/"
#define MAX_POWER 9

#include "utils/FileAPI.h"
#include "utils/Arrays.h"

int get2Power(int value) {
    static constexpr int twos[] = {
            1 << 0, 1 << 1, 1 << 2,
            1 << 3, 1 << 4, 1 << 5,
            1 << 6, 1 << 7, 1 << 8, 1 << 9
    };
    return std::lower_bound(std::begin(twos), std::end(twos), value) - std::begin(twos);
}

int findSearchedPower(int searched_index, const int *counter) {
    int result = MAX_POWER;
    for (; searched_index >= 0; searched_index -= counter[result - 1]) result--;
    return result - 1;
}

void solve() {
    setInputFolder(CONTENT_ROOT);
    initialiseFiles(FILE_NAME);

    auto searched_index = readFromFile<int>();

    auto *counter = emptyArray<int>(MAX_POWER);
    while (!isFileEmpty()) counter[get2Power(readFromFile<int>())]++;

    int power = findSearchedPower(searched_index, counter) - 1;
    writeToFile(*new string((power < 1 ? "Nu exista" : to_string((2 << power)))));
}


#endif

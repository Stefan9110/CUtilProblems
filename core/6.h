/**
 * https://www.pbinfo.ro/probleme/2683/easy-ssc
 * O(n) req
 */
#ifndef PROBLBAC_6_H
#define PROBLBAC_6_H

#include <iostream>
#include "utils/List.h"
#include "utils/Arrays.h"

bool modifyMinValue(List<int> *previousList, int toModify) {
    for (List<int> *it = previousList; it != nullptr; it = it->next_ptr()) {
        if (toModify <= it->value()) continue;
        it->modifyValue(toModify);
        return true;
    }
    return false;
}

unsigned int findMinPartition(const int *arr, size_t length) {
    auto *previous = new List<int>(arr[0]);
    for (int i = 1; i < length; i++) if (!modifyMinValue(previous, arr[i])) previous->add(arr[i]);
    return previous->length();
}

void solve_6() {
    size_t length = 0;
    std::cout << findMinPartition(readArray < int > (length), length);
}

#endif //PROBLBAC_6_H

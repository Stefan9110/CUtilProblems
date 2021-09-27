/**
 * https://www.pbinfo.ro/probleme/2271/prodmax1
 */
#ifndef PROBLBAC_PBINFO_2271_H
#define PROBLBAC_PBINFO_2271_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include "utils/Arrays.h"

long long findMax(const int *positive, const int *negative, int positiveIteration, int negativeIteration) {
    long long positiveProd = -2147483648, negativeProd = -2147483648;
    for (int i = 0; i < positiveIteration; i++) {
        if (i == 0) positiveProd = positive[0];
        else positiveProd *= positive[i];
    }
    for (int i = 0; i < negativeIteration; i++) {
        if (i == 0) negativeProd = negative[0];
        else negativeProd *= negative[i];
    }

    return std::max(positiveProd, negativeProd);
}

void solve() {
    size_t length;
    auto *arr = readArray<int>(length);

    std::sort(arr, arr + length,
              [](int val1, int val2) {
                  if (abs(val1) == abs(val2)) return val1 > val2;
                  return abs(val1) > abs(val2);
              }
    );

    auto *positive = new int[2], *negative = new int[2];
    int positiveIteration = 0, negativeIteration = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] >= 0) {
            if (positiveIteration < 2) positive[positiveIteration++] = arr[i];
        } else if (negativeIteration < 2) negative[negativeIteration++] = arr[i];
        if (positiveIteration == 2 && negativeIteration == 2) break;
    }

    std::cout << findMax(positive, negative, positiveIteration, negativeIteration);
}

#endif

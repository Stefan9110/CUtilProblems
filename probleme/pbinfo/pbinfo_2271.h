/**
 * https://www.pbinfo.ro/probleme/2271/prodmax1
 */
#ifndef PROBLBAC_PBINFO_2271_H
#define PROBLBAC_PBINFO_2271_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include "utils/Arrays.h"

long long calculateProd(const int *arr, short length) {
    long long result = -2147483648;
    for (int i = 0; i < length; i++) result = (i == 0 ? arr[0] : result * arr[i]);
    return result;
}

long long findMax(const int *positive, const int *negative, short positive_length, short negative_length) {
    return std::max(calculateProd(positive, positive_length), calculateProd(negative, negative_length));
}

int *getMax2(const int *arr, const size_t arr_length, short &length, bool positive) {
    int *result = new int[2];
    length = 0;
    for (int i = 0; i < arr_length && length < 2; i++) if (positive == arr[i] >= 0) result[length++] = arr[i];
    return result;
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

    short pos_length, neg_length;
    auto *pos_arr = getMax2(arr, length, pos_length, true), *neg_arr = getMax2(arr, length, neg_length, false);
    std::cout << findMax(pos_arr, neg_arr, pos_length, neg_length);
}

#endif

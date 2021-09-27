/**
 * https://www.pbinfo.ro/resurse/9dc152/examene/2020/E_d_Informatica_2020_sp_MI_C_var_05_LRO.pdf
 * III.1
 */

#ifndef PROBLBAC_BAC_2020_IUN_III_1_H
#define PROBLBAC_BAC_2020_IUN_III_1_H

#include <iostream>

bool isValid(int number) {
    int sum = 1 + (number == 1 ? 0 : number);
    for (int i = 2; i * i <= number; i++) sum += (number % i == 0 ? i + (i * i == number ? 0 : number / i) : 0);
    return sum % 2 == number % 2;
}

int findKValid(int start, int end, int k) {
    for (int i = start; i <= end && k > 0; i++) if (isValid(i) && --k == 0) return i;
    return -1;
}

void solve() {
    int start, end, k;
    std::cin >> start >> end >> k;
    std::cout << findKValid(start, end, k);
}

#endif

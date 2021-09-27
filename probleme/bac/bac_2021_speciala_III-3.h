#ifndef PROBLBAC_BAC_2021_SPECIALA_III_3_H
#define PROBLBAC_BAC_2021_SPECIALA_III_3_H

/**
 * https://www.pbinfo.ro/resurse/9dc152/examene/2021/ses_speciala/E_d_Informatica_2021_sp_MI_C_var_07.pdf
 * III.3
 */
#include <iostream>

void solve() {
    int firstIntegers[2];
    std::cin >> firstIntegers[0] >> firstIntegers[1];

    int solution = 1;
    for (int i = 0; i < (firstIntegers[1] - firstIntegers[0]) / 2 + 1; i++) {
        solution += 2 * i;
        std::cout << solution << " ";
    }
}

#endif

#ifndef PROBLBAC_2_H
#define PROBLBAC_2_H
/**
 * https://www.pbinfo.ro/resurse/9dc152/examene/2021/ses_speciala/E_d_Informatica_2021_sp_MI_C_var_07.pdf
 * III.2
 */

#include <iostream>

int **readArray(unsigned int length) {
    int **result = new int *[length];
    for (int i = 0; i < length; i++) result[i] = new int[length];
    for (int i = 0; i < length; i++) for (int j = 0; j < length; j++) std::cin >> result[i][j];
    return result;
}

void swap_matrix(int **matrix, const unsigned int length) {
    for (int j = 0; j < length - 1; j++) std::swap(matrix[length - 2][j], matrix[j][length - 2]);
}

void print(int **matrix, const unsigned int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void solve_2() {
    unsigned int length;
    std::cin >> length;
    int **matrix = readArray(length);
    swap_matrix(matrix, length);
    print(matrix, length);
}

#endif

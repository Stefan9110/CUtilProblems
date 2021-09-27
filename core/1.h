//
// Created by Stefan Halasz on 27.09.2021.
//

#ifndef PROBLBAC_1_H
#define PROBLBAC_1_H

#include <iostream>
const std::string vowels = "aeiou";

int getDivisorCount(int &number, int divisor) {
    int result = 0;
    while (number % divisor == 0) {
        result++;
        number /= divisor;
    }
    return result;
}

void divPrim(int number, int &sum) {
    int divisor = 2;
    while (number > 1) {
        if (getDivisorCount(number, divisor) % 2 == 1) sum += divisor;
        divisor++;
    }
}

void printFirstK(int k, int n) {
    bool found = false;
    while (--n != 0 && k > 0) {
        std::string current;
        std::cin >> current;

        if (vowels.find(current.at(current.length() - 1)) == std::string::npos) continue;

        std::cout << current << "\n";
        --k;
        found = true;
    }

    std::cout << (found ? "" : "nu exista");
}

int f_reverse(int num) {
    int result = 0;
    while (num > 0) {
        result = result * 10 + num % 10;
        num /= 10;
    }
    return result;
}

int stripFromEven(int num, bool reverse) {
    int result = 0;
    while (num > 0) {
        if (((num % 10) % 2)) result = result * 10 + (num % 10);
        num /= 10;
    }

    return (reverse ? result : f_reverse(result));
}

void imog(int num1, int num2, bool &rez) {
    rez = stripFromEven(num1, false) == stripFromEven(num2, true);
}

#endif //PROBLBAC_1_H

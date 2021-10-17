#ifndef PROBLBAC_PBINFO_1340_H
#define PROBLBAC_PBINFO_1340_H

#include <iostream>
#include <queue>
#include <algorithm>

class Backpack {
private:
    double weight_, value_;

public:
    double getRatio() const {
        return value_ / weight_;
    }

    double weight() const {
        return weight_;
    }

    double value() const {
        return value_;
    }

    friend std::istream &operator>>(std::istream &is, Backpack &backpack) {
        is >> backpack.weight_ >> backpack.value_;
        return is;
    }
};

void solve() {
    int length;
    double gMax;
    std::cin >> length >> gMax;

    auto *arr = new Backpack[length];
    for (int i = 0; i < length; i++) std::cin >> arr[i];

    double currentG = 0, currentValue = 0;
    std::sort(arr, arr + length, [](Backpack b1, Backpack b2) {
        return b1.getRatio() > b2.getRatio();

    });

    for (int i = 0; i < length && currentG <= gMax; i++) {
        if (currentG + arr[i].weight() >= gMax) {
            currentValue += ((gMax - currentG) / arr[i].weight()) * arr[i].value();
            currentG = gMax;
        } else {
            currentValue += arr[i].value();
            currentG += arr[i].weight();
        }
    }

    std::cout << currentValue;
}

#endif //PROBLBAC_PBINFO_1340_H

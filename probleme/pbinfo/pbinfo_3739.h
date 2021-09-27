/**
 * https://www.pbinfo.ro/probleme/3739/cafea
 */
#ifndef PROBLBAC_PBINFO_3739_H
#define PROBLBAC_PBINFO_3739_H

#include "utils/FileAPI.h"
#include "utils/Arrays.h"
#include <cmath>
#include <algorithm>

#define FILE_NAME "cafea"

class Seller {
private:
    unsigned long selling_quantity_, price_;

public:
    Seller(unsigned long selling_quantity, unsigned long price) {
        this->selling_quantity_ = selling_quantity;
        this->price_ = price;
    }

    Seller() {
        this->selling_quantity_ = 1;
        this->price_ = 1;
    }

    unsigned long price() const {
        return this->price_;
    }

    unsigned long selling_quantity() const {
        return this->selling_quantity_;
    }

    unsigned long priceOf(unsigned long quantity) const {
        return ceil(singletonPrice() * quantity);
    }

    double singletonPrice() const {
        return (double) price() / selling_quantity();
    }

    unsigned long priceOf(unsigned long maxMoney, unsigned long &maxQuantity) const {
        unsigned long purchasedQuantity = (maxQuantity > selling_quantity()) ? selling_quantity() : maxQuantity,
                totalPrice = priceOf(purchasedQuantity);

        if (totalPrice >= maxMoney) {
            purchasedQuantity = (unsigned long) floor((double) maxMoney / singletonPrice());
            totalPrice = maxMoney;
        }

        maxQuantity -= purchasedQuantity;
        return totalPrice;
    }

    friend istream &operator>>(istream &input, Seller &seller) {
        input >> seller.selling_quantity_ >> seller.price_;
        return input;
    }
};

unsigned long findRequiredMoney(Seller *seller_array,
                                size_t array_length,
                                unsigned long quantity,
                                unsigned long maxMoney) {
    for (size_t i = 0; i < array_length && quantity > 0 && maxMoney > 0; i++)
        maxMoney -= seller_array[i].priceOf(maxMoney, quantity);
    return maxMoney;
}


void solve() {
    setInputFolder(R"(C:\Users\danie\CUtilProblems\input-files\)");
    initialiseFiles(FILE_NAME);
    auto requiredQuantity = readFromFile<unsigned long>(),
            maxMoney = readFromFile<unsigned long>();
    auto sellersLength = readFromFile<size_t>();
    auto *sellerArray = readArray<Seller>(sellersLength, file_in);

    auto sort_cmp = [](Seller seller1, Seller seller2) {
        double singletonPrice1 = seller1.singletonPrice(), singletonPrice2 = seller2.singletonPrice();
        if (singletonPrice1 == singletonPrice2) return seller1.price() < seller2.price();
        return singletonPrice1 < singletonPrice2;
    };

    sort(sellerArray, sellerArray + sellersLength, sort_cmp);
    writeToFile(findRequiredMoney(sellerArray, sellersLength, requiredQuantity, maxMoney));
    closeFiles();
}


#endif //PROBLBAC_PBINFO_3739_H

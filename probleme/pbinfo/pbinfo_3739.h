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

    /**
     * @return Price of the entire stock
     */
    unsigned long price() const {
        return this->price_;
    }

    /**
     * @return The amount of coffee in stock
     */
    unsigned long selling_quantity() const {
        return this->selling_quantity_;
    }

    /**
     * Rounded (up) price of given quantity
     * @param quantity The quantity of coffee the price shall be calculated for
     * @return Price of $quantity amount of coffee
     */
    unsigned long priceOf(unsigned long quantity) const {
        return ceil(singletonPrice() * quantity);
    }

    /**
     * @return Price per unit of the given seller (not rounded)
     */
    double singletonPrice() const {
        return (double) price() / selling_quantity();
    }

    unsigned long priceOf(unsigned long maxMoney, unsigned long &maxQuantity) const {
        // If the seller does not have the amount we need in stock just buy the entire stock
        unsigned long purchasedQuantity = (maxQuantity > selling_quantity()) ? selling_quantity() : maxQuantity,
                totalPrice = priceOf(purchasedQuantity); // Calculate payment to seller

        /* If the payment to the seller costs us more than the amount of money we have
         * purchase as much as we can from this (greedy selected) seller
         */
        if (totalPrice >= maxMoney) {
            purchasedQuantity = (unsigned long) floor((double) maxMoney / singletonPrice());
            totalPrice = maxMoney;
        }

        maxQuantity -= purchasedQuantity; // Subtract the purchased quantity from the quantity we need
        return totalPrice; // Return the amount of money paid for the quantity
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
        // Subtract amount paid for max quantity purchased from greedy selected seller
        maxMoney -= seller_array[i].priceOf(maxMoney, quantity);
    return maxMoney; // money left after purchasing from sellers
}

void solve() {
    // Initialize problem data
    setInputFolder(R"(C:\Users\danie\CUtilProblems\input-files\pbinfo_3739\)"); // Remove this line when uploading to pbinfo
    initialiseFiles(FILE_NAME);
    auto requiredQuantity = readFromFile<unsigned long>(),
            maxMoney = readFromFile<unsigned long>();
    size_t sellersLength;
    auto *sellerArray = readArray<Seller>(sellersLength, file_in);

    /* Greedy sorting the seller array by
     * the price per unit. If the price per unit
     * is the same for two different sellers, sort
     * by total price
     */
    sort(sellerArray, sellerArray + sellersLength,
         [](Seller seller1, Seller seller2) {
             double singletonPrice1 = seller1.singletonPrice(), singletonPrice2 = seller2.singletonPrice();
             return singletonPrice1 == singletonPrice2 ?
                    seller1.price() < seller2.price() : singletonPrice1 < singletonPrice2;
         }
    );
    // Print result to file
    writeToFile(findRequiredMoney(sellerArray, sellersLength, requiredQuantity, maxMoney));
    closeFiles();
}

#endif
//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_CUSTOMER_H
#define BANK_SYSTEM_CUSTOMER_H

#include "String.h"

class Customer {
private:
    size_t id;
    String name;
    String address;

public:
    Customer() = default;

    Customer(const Customer &other) = default;

    Customer &operator=(const Customer &other) = default;

    Customer(size_t id, const String &name, const String &address);

    const String &getName() const;

    const String &getAddress() const;

    size_t getId() const;

    void print() const;
};


#endif //BANK_SYSTEM_CUSTOMER_H

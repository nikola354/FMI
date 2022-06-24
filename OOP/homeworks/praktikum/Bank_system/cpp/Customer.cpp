//
// Created by nikola354 on 01.06.22.
//

#include "../headers/Customer.h"

size_t Customer::getId() const {
    return id;
}

const String &Customer::getAddress() const {
    return address;
}

const String &Customer::getName() const {
    return name;
}

Customer::Customer(size_t id, const String &name, const String &address) {
    this->id = id;
    this->name = name;
    this->address = address;
}

void Customer::print() const {
    std::cout << id << ". " << name << ", address: " << address << std::endl;
}

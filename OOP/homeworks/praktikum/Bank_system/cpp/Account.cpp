//
// Created by nikola354 on 01.06.22.
//

#include "../headers/Account.h"

double Account::getBalance() const {
    return amount;
}

void Account::deposit(double value) {
    amount += value;
}

void Account::display() const {
    using namespace std;

    cout << "iban: " << iban << "| owner id: " << ownerId << "| balance: " << amount;
}

size_t Account::getOwnerId() const {
    return ownerId;
}

const String &Account::getIban() const {
    return iban;
}

const String &Account::getUsername() const {
    return username;
}

const String &Account::getPassword() const {
    return password;
}

Account::Account(const String &username, const String &password, const String &iban, size_t ownerId, double amount) {
    this->username = username;
    this->password = password;
    this->iban = iban;
    this->ownerId = ownerId;
    this->amount = amount;
    dateOfCreation = time(0);
}

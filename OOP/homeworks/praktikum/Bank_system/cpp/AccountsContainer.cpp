//
// Created by nikola354 on 01.06.22.
//

#include "../headers/AccountsContainer.h"

AccountsContainer::AccountsContainer() {
    capacity = 4;
    size = 0;
    accounts = new Account *[capacity];
}

AccountsContainer::~AccountsContainer() {
    free();
}

void AccountsContainer::free() {
    for (int i = 0; i < size; ++i) {
        delete accounts[i];
    }
    delete [] accounts;
}

void AccountsContainer::resize() {
    capacity *= 2;
    Account **temp = new Account*[capacity];

    for (int i = 0; i < size; ++i) {
        temp[i] = accounts[i];
    }
    delete[] accounts;
    accounts = temp;
}

void AccountsContainer::addAccount(const Account *obj) {
    if (size >= capacity)
        resize();

    accounts[size++] = obj->clone();
}

const Account *AccountsContainer::getAccountByIban(const String &iban) const {
    for (int i = 0; i < size; ++i) {
        if (accounts[i]->getIban() == iban)
            return accounts[i];
    }
    return nullptr;
}

Account *AccountsContainer::getAccountByIban(const String &iban) {
    for (int i = 0; i < size; ++i) {
        if (accounts[i]->getIban() == iban)
            return accounts[i];
    }
    return nullptr;
}

void AccountsContainer::deleteRelatedAccounts(const Customer &customer, Log &log) {
    for (int i = 0; i < size; ++i) {
        if (accounts[i]->getOwnerId() == customer.getId()) {
            deleteAccount(i, log);
        }
    }
}

bool AccountsContainer::deleteAccount(const String &iban, Log &log) {
    for (int i = 0; i < size; ++i) {
        if (accounts[i]->getIban() == iban) {
            deleteAccount(i, log);
            return true;
        }
    }

    return false;
}

void AccountsContainer::deleteAccount(size_t index, Log &log) {
    log.deleteAccount(accounts[index]);

    delete accounts[index];
    accounts[index] = accounts[--size];
    accounts[size] = nullptr;
}

void AccountsContainer::listAccounts() const {
    for (int i = 0; i < size; ++i) {
        accounts[i]->display();
    }
}

void AccountsContainer::listAccounts(size_t customerId) const {
    for (int i = 0; i < size; ++i) {
        if (accounts[i]->getOwnerId() == customerId)
            accounts[i]->display();
    }
}

size_t AccountsContainer::getSize() const {
    return size;
}

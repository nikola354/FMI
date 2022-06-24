//
// Created by nikola354 on 01.06.22.
//

#include "../headers/Log.h"


void Log::addCustomer(const Customer &customer) {
    String event("ADDED customer with id ");
    event += toStr(customer.getId());

    log.pushBack(event);
}

void Log::addAccount(const Account *account) {
    String event("ADDED account with iban: ");
    event += account->getIban();

    log.pushBack(event);
}

void Log::deleteCustomer(const Customer &customer) {
    String event("DELETED customer with id ");
    event += toStr(customer.getId());

    log.pushBack(event);
}

void Log::deleteAccount(const Account *account) {
    String event("DELETED account with iban: ");
    event += account->getIban();

    log.pushBack(event);
}

void Log::exportLog() {
    std::ofstream writeFile(LOG_FILENAME, std::ios::app);

    for (int i = exportedTillIIndex; i < log.getSize(); ++i) {
        writeFile << log[i] << std::endl;
    }

    exportedTillIIndex = log.getSize() - 1;
}

void Log::display() const {
    for (int i = 0; i < log.getSize(); ++i) {
        std::cout << log[i] << std::endl;
    }
}

void Log::withdraw(const Account *account) {
    String event("WITHDRAW from account with iban: ");

    event += account->getIban();

    log.pushBack(event);
}

void Log::deposit(const Account *account) {
    String event("DEPOSIT to account with iban: ");

    event += account->getIban();

    log.pushBack(event);
}

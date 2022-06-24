//
// Created by nikola354 on 01.06.22.
//

#include "../headers/Bank.h"

bool Bank::addCustomer(const Customer &customer) {
    for (int i = 0; i < customers.getSize(); ++i) {
        if (customers[i].getId() == customer.getId())
            return false; //if this customer already exists, break
    }

    customers.pushBack(customer);
    log.addCustomer(customer);
    return true;
}

bool Bank::addAccount(const Account *account) {
    size_t accountOwnerId = account->getOwnerId();

    if (getCustomerById(accountOwnerId) == nullptr)
        return false;

    if (accounts.getAccountByIban(account->getIban()) != nullptr) //account with this iban already exists
        return false;

    accounts.addAccount(account);
    log.addAccount(account);
    return true;
}

const Customer *Bank::getCustomerById(size_t id) const {
    for (int i = 0; i < customers.getSize(); ++i) {
        if (customers[i].getId() == id)
            return &customers[i];
    }

    return nullptr;
}

bool Bank::deleteCustomer(size_t id) {
    int index = getCustomerIndexById(id);

    if (index == -1)
        return false;

    Customer deleted = customers.popAt(index);
    accounts.deleteRelatedAccounts(deleted, log);
    log.deleteCustomer(deleted);
    return true;
}

bool Bank::deleteAccount(const String &iban) {
    return accounts.deleteAccount(iban, log);
}

void Bank::exportLog() {
    log.exportLog();
}

void Bank::listCustomers() const {
    for (int i = 0; i < customers.getSize(); ++i) {
        customers[i].print();
    }
}

void Bank::listAccounts() const {
    accounts.listAccounts();
}

bool Bank::listCustomerAccount(size_t customerId) const {
    if (getCustomerById(customerId) == nullptr)
        return false;

    accounts.listAccounts(customerId);
    return true;
}

void Bank::display() const {
    std::cout << "name: " << name << " | address: " << address << " | customers count: " << customers.getSize() << " | accounts count: "
              << accounts.getSize() << std::endl;
}

bool Bank::transfer(double amount, const String &fromIban, const String &toIban) {
    Account *from = accounts.getAccountByIban(fromIban);
    Account *to = accounts.getAccountByIban(toIban);

    if (from == nullptr || to == nullptr)
        return false;

    if (!from->withdraw(amount)) //check if we can get the money from the first acc
        return false;

    to->deposit(amount);
    return true;
}

int Bank::getCustomerIndexById(size_t id) const {
    for (int i = 0; i < customers.getSize(); ++i) {
        if (customers[i].getId() == id)
            return i;
    }
    return -1;
}

void Bank::displayLog() const {
    log.display();
}

const Account *Bank::getAccountByIban(const String &iban) const {
    return accounts.getAccountByIban(iban);
}

bool Bank::withdraw(double amount, const String &fromIban) {
    Account *toWithdraw = accounts.getAccountByIban(fromIban);

    if (toWithdraw == nullptr)
        return false;


    if (!toWithdraw->withdraw(amount))
        return false;

    log.withdraw(toWithdraw);
    return true;
}

bool Bank::deposit(double amount, const String &iban) {
    Account *toDeposit = accounts.getAccountByIban(iban);

    if (toDeposit == nullptr)
        return false;

    toDeposit->deposit(amount);
    log.deposit(toDeposit);
    return true;
}

Bank::Bank(const String &name, const String &address) {
    this->name = name;
    this->address = address;
}


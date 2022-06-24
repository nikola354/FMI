//
// Created by nikola354 on 01.06.22.
//

#include "../headers/NormalAccount.h"

bool NormalAccount::withdraw(double value) {
    if (value > amount)
        return false;

    amount -= value;
    return true;
}

void NormalAccount::display() const {
    std::cout << "Normal account| ";
    Account::display();
    std::cout << std::endl;
}

Account *NormalAccount::clone() const {
    return new NormalAccount(*this);
}

NormalAccount::NormalAccount(const String &username, const String &password, const String &iban, size_t ownerId, double amount)
        : Account(username,
                  password,
                  iban,
                  ownerId,
                  amount) {
    type = Account::Type::NORMAL;

}

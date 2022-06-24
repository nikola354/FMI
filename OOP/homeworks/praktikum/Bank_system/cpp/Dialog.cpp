//
// Created by nikola354 on 01.06.22.
//

#include "../headers/Dialog.h"

using namespace std;

void Dialog::welcomeDialog() {
    cout << "Welcome!" << endl;
    String cmd;

    while (true) {
        cout << ">";
        cmd.getLine(cin);
        cmd.trim();

        if (cmd == "quit") {
            return;
        } else if (cmd == "edit") {
            editDialog();
        } else if (cmd == "list") {
            listDialog();
        } else if (cmd == "action") {
            actionDialog();
        } else if (cmd == "display") {
            bank.display();
        } else if (cmd == "export log") {
            bank.exportLog();
        }
    }
}

void Dialog::editDialog() {
    String answer;

    while (true) {
        cout << "Account or customer? ";

        answer.getLine(cin);

        if (answer.isEqualIgnoreCase("account")) {
            editAccountDialog();
            return;
        } else if (answer.isEqualIgnoreCase("customer")) {
            editCustomerDialog();
            return;
        }

        cout << "We did not get that :(" << endl;
    }
}

void Dialog::editCustomerDialog() {
    String answer;

    while (true) {
        cout << "Add or delete? ";

        answer.getLine(cin);

        if (answer.isEqualIgnoreCase("add")) {
            addCustomerDialog();
            return;
        } else if (answer.isEqualIgnoreCase("delete")) {
            deleteCustomerDialog();
            return;
        }
        cout << "We did not get that :(" << endl;
    }
}

void Dialog::editAccountDialog() {
    String answer;

    while (true) {
        cout << "Add or delete? ";

        answer.getLine(cin);

        if (answer.isEqualIgnoreCase("add")) {
            addAccountDialog();
            return;
        } else if (answer.isEqualIgnoreCase("delete")) {
            deleteAccountDialog();
            return;
        }
        cout << "We did not get that :(" << endl;
    }
}

void Dialog::addCustomerDialog() {
    cout << "Name: ";
    String name;
    name.getLine(cin);

    cout << "Address: ";
    String address;
    address.getLine(cin);

    bank.addCustomer(Customer(customerId++, name, address));
}

void Dialog::addAccountDialog() {
    String answer;
    String type;

    while (true) {
        cout << "Normal, savings or privilege? ";

        answer.getLine(cin);

        if (!answer.isEqualIgnoreCase("normal") && !answer.isEqualIgnoreCase("savings") && !answer.isEqualIgnoreCase("privilege"))
            cout << "We did not get that :(" << endl;
        else
            break;
    }

    while (true) {
        cout << "username: ";
        String username;
        username.getLine(cin);

        cout << "password: ";
        String password;
        password.getLine(cin);

        cout << "iban: ";
        String iban;
        iban.getLine(cin);

        cout << "customer id (the customer with this id will be the owner of the account): ";
        String id;
        id.getLine(cin);
        if (!id.isPositiveNumber()) {
            cout << positiveNumberError("id") << endl;
            continue;
        }

        cout << "balance: ";
        String balance;
        balance.getLine(cin);
        if (!balance.isPositiveDouble()) {
            cout << positiveDoubleError("balance") << endl;
            continue;
        }

        if (answer.isEqualIgnoreCase("normal")) {
            if (!bank.addAccount(new NormalAccount(username, password, iban, id.toNumber(), balance.toDouble()))
                    ) {
                cout << "The iban of the account is already in use or there is no customer with this id!" << endl;
            } else {
                cout << "Success!" << endl;
            }
            return;
        } else if (answer.isEqualIgnoreCase("savings")) {
            cout << "interest rate in %: ";
            String interestRate;
            interestRate.getLine(cin);
            if (!interestRate.isPositiveDouble()) {
                cout << positiveDoubleError("interest rate") << endl;
                continue;
            }

            if (!bank.addAccount(new SavingsAccount(username, password, iban, id.toNumber(), balance.toDouble(), interestRate.toDouble()))) {
                cout << "The iban of the account is already in use or there is no customer with this id!" << endl;
            } else {
                cout << "Success!" << endl;
            }
            return;
        } else if (answer.isEqualIgnoreCase("privilege")) {
            cout << "overdraft: ";
            String overdraft;
            overdraft.getLine(cin);
            if (!overdraft.isPositiveDouble()) {
                cout << positiveDoubleError("overdraft") << endl;
                continue;
            }

            if (!bank.addAccount(new PrivilegeAccount(username, password, iban, id.toNumber(), balance.toDouble(), overdraft.toDouble()))) {
                cout << "The iban of the account is already in use or there is no customer with this id!" << endl;
            } else {
                cout << "Success!" << endl;
            }
            return;
        }
    }

}

void Dialog::deleteCustomerDialog() {
    size_t id = getCustomerIdDialog();

    if (!bank.deleteCustomer(id))
        cout << "There is no user with this id!" << endl;
}

void Dialog::deleteAccountDialog() {
    String iban = getAccountIbanDialog();

    if (!bank.deleteAccount(iban))
        cout << "There is no account with this iban!" << endl;
}

void Dialog::listDialog() {
    while (true) {
        cout << "All customers, all accounts, customer accounts, log? ";
        String answer;
        answer.getLine(cin);

        if (answer.isEqualIgnoreCase("all customers")) {
            bank.listCustomers();
            return;
        } else if (answer.isEqualIgnoreCase("all accounts")) {
            bank.listAccounts();
            return;
        } else if (answer.isEqualIgnoreCase("customer accounts")) {
            listCustomerAccountsDialog();
            return;
        } else if (answer.isEqualIgnoreCase("log")) {
            bank.displayLog();
            return;
        }
    }
}

void Dialog::listCustomerAccountsDialog() {
    size_t id = getCustomerIdDialog();

    if (!bank.listCustomerAccount(id))
        cout << "There is no customer with this id!" << endl;
}

size_t Dialog::getCustomerIdDialog() {
    while (true) {
        cout << "Enter customer id: ";
        String id;
        id.getLine(cin);

        if (!id.isPositiveNumber()) {
            cout << positiveNumberError("id") << endl;
            continue;
        }

        return id.toNumber();
    }
}

void Dialog::actionDialog() {
    while (true) {

        cout << "Withdraw, deposit or transfer? ";
        String answer;
        answer.getLine(cin);

        if (answer.isEqualIgnoreCase("withdraw")) {
            withdrawDialog();
            return;
        } else if (answer.isEqualIgnoreCase("deposit")) {
            depositDialog();
            return;
        } else if (answer.isEqualIgnoreCase("transfer")) {
            transferDialog();
            return;
        }
    }

}

String Dialog::getAccountIbanDialog() {
    cout << "Enter iban: ";
    String iban;
    iban.getLine(cin);

    return iban;
}

void Dialog::withdrawDialog() {
    String iban = getAccountIbanDialog();

    double amount = getAmountDialog();

    if (!bank.withdraw(amount, iban))
        cout << "There is no account with this iban or there is not enough balance to do this transaction!" << endl;
    else
        cout << "Success!" << endl;
}

void Dialog::depositDialog() {
    String iban = getAccountIbanDialog();

    double amount = getAmountDialog();

    if (!bank.deposit(amount, iban))
        cout << "There is no account with this iban!" << endl;
    else
        cout << "Success!" << endl;
}

void Dialog::transferDialog() {
    cout << "From account -> ";
    String fromIban = getAccountIbanDialog();

    cout << "To account -> ";
    String toIban = getAccountIbanDialog();

    double amount = getAmountDialog();

    if (!bank.transfer(amount, fromIban, toIban))
        cout << "There is no account with this iban or there is not enough balance to do this transaction!" << endl;
    else
        cout << "Success!" << endl;
}

double Dialog::getAmountDialog() {
    String amount;
    while (true) {
        cout << "Enter amount: ";
        amount.getLine(cin);

        if (!amount.isPositiveDouble()) {
            cout << positiveDoubleError("amount") << endl;
        }

        return amount.toDouble();
    }
}

Dialog::Dialog() {
    bank = Bank("UniCredit", "Sofia, bul....");
    customerId = 0;
}

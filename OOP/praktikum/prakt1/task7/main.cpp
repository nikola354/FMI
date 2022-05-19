#include <iostream>
#include <fstream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_LENGTH = 128;
const int MAX_USERS = 100;
const char FILENAME[] = "users.txt";
const char *LOGIN_CMD = "login";
const char *REGISTER_CMD = "register";

struct User {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct System {
    User users[MAX_USERS];
    int size = 0;
};

//FILE FUNCTIONS:

void writeUserToFile(const User &user, ofstream &writeFile);

bool writeSystemToFile(const System &sys);

void readUserFromFile(User &user, ifstream &readFile);

bool readSystemFromFile(System &sys);

bool isStrEqual(const char *str1, const char *str2);

// HELPERS:

unsigned my_strlen(const char *str);

bool isStrEqual(const char *str1, const char *str2);

void my_strcopy(char *destination, const char *source);

bool emailExists(const System &sys, const char *email);

// MENUS:

void loadMenu(System &sys);

void registerMenu(System &sys);

void loginMenu(System &sys);

int main() {
    //test

    ofstream writeFile ("test.csv");

    writeFile << "banana," << "another fruit" << endl;
    writeFile << "apple" << endl;

    writeFile.close();

    string banana, another, apple;

    ifstream readFile("test.csv");

    readFile >> banana;

    cout << banana << endl;
    //todo: implement csv

    //end


    System system;

    if (!readSystemFromFile(system)) {
        cout << "Something went wrong..." << endl;
    }

    loadMenu(system);

    if (!writeSystemToFile(system)) {
        cout << "Something went wrong..." << endl;
    }

    return 0;
}

void writeUserToFile(const User &user, ofstream &writeFile) {
    writeFile << user.name << endl;
    writeFile << user.email << endl;
    writeFile << user.password << endl;

}

bool writeSystemToFile(const System &sys) {
    ofstream writeFile(FILENAME);

    if (!writeFile.is_open()) {
        return false;
    }

    writeFile << sys.size << endl; //the first line of the file is the number of users

    for (int i = 0; i < sys.size; ++i) {
        writeFile << endl;
        writeUserToFile(sys.users[i], writeFile);
    }
    writeFile.close();
    return true;
}

void readUserFromFile(User &user, ifstream &readFile) {
    readFile >> user.name >> user.email >> user.password;
}

bool readSystemFromFile(System &sys) {
    ifstream readFile(FILENAME);

    if (!readFile.is_open()) {
        return false;
    }

    readFile >> sys.size; //the first line of the file is the number of users
    char buffer[2];

    for (int i = 0; i < sys.size; ++i) {
        readFile.getline(buffer, 2);
        readUserFromFile(sys.users[i], readFile);
    }

    readFile.close();
    return true;
}

unsigned my_strlen(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

bool isStrEqual(const char *str1, const char *str2) {
    unsigned str1Length = my_strlen(str1);
    unsigned str2Length = my_strlen(str2);

    if (str1Length != str2Length) return false;

    for (int i = 0; i < str1Length; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

void my_strcopy(char *destination, const char *source) {
    int sourceLength = my_strlen(source);

    int i = 0;
    for (; i < sourceLength; ++i) {
        destination[i] = source[i];
    }
    destination[i] = TERMINATE_SYMBOL;
}

bool emailExists(const System &sys, const char *email) {
    for (int i = 0; i < sys.size; ++i) {
        if (isStrEqual(sys.users[i].email, email))
            return true;
    }
    return false;
}


const User &getUser(const System &sys, const char *email) {
    for (int i = 0; i < sys.size; ++i) {
        if (isStrEqual(sys.users[i].email, email))
            return sys.users[i];
    }
}


void loadMenu(System &sys) {
    cout << "Enter command: " << endl;
    bool repeat = false;
    char *command = new char;

    do {
        cin >> command;

        if (isStrEqual(command, LOGIN_CMD)) {
            return loginMenu(sys);
        } else if (isStrEqual(command, REGISTER_CMD)) {
            if (sys.size >= MAX_USERS) {
                cout << "No space for more users!" << endl;
                repeat = true;
            }

            registerMenu(sys);
        } else {
            cout << "Wrong command! Try again.." << endl;
            repeat = true;
        }
    } while (repeat);
}

void registerMenu(System &sys) {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char password[MAX_LENGTH];

    cout << "Enter name:" << endl;
    cin >> name;
    cout << "Enter email:" << endl;
    cin >> email;

    while (emailExists(sys, email)) { //while the user enters a taken email address
        cout << "This email is taken! Try another one: " << endl;
        cin >> email;
    }

    cout << "Enter password:" << endl;
    cin >> password;

    int currentIndex = sys.size;
    my_strcopy(sys.users[currentIndex].name, name);
    my_strcopy(sys.users[currentIndex].email, email);
    my_strcopy(sys.users[currentIndex].password, password);
    sys.size++;

    cout << "Registered successfully!" << endl;
}

void loginMenu(System &sys) {
    char email[MAX_LENGTH];
    char password[MAX_LENGTH];

    bool repeat = false;
    do{
        cout << "Enter email:" << endl;
        cin >> email;
        cout << "Enter password:" << endl;
        cin >> password;

        if (!emailExists(sys, email)) {
            cout << "The email you entered is not in our system!" << endl;
            repeat = true;
        }

        User user = getUser(sys, email);

        if (isStrEqual(user.password, password)) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Wrong password! Try again..." << endl;
            repeat = true;
        }
    } while (repeat);
}

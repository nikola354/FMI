#include "Kindle.h"

Kindle::Kindle() {
    std::ifstream usersFile(USERS_FILE);

    if (usersFile.is_open()) {
        char buffer[FILE_BUFFER_SIZE];

        usersFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);

        usersCount = toNumber(buffer);
        usersCapacity = usersCount + 1;
        users = new User[usersCapacity];

        for (int i = 0; i < usersCount; ++i) {
            users[i] = User(usersFile);
        }
        usersFile.close();
    } else {
        usersCount = 0;
        usersCapacity = 1;
        users = new User[usersCapacity];
    }

    std::ifstream booksFile(BOOKS_FILE);

    if (booksFile.is_open()) {
        char buffer[FILE_BUFFER_SIZE];

        booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);

        booksCount = toNumber(buffer);
        booksCapacity = booksCount + 1;
        books = new Book[booksCapacity];

        for (int i = 0; i < booksCount; ++i) {
            books[i] = Book(booksFile);
        }

        booksFile.close();
    } else {
        booksCount = 0;
        booksCapacity = 1;
        books = new Book[booksCapacity];
    }

}

Kindle::Kindle(const Kindle &other) {
    copyFrom(other);
}

Kindle &Kindle::operator=(const Kindle &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Kindle::~Kindle() {
    free();
}

void Kindle::free() {
    delete[] books;
    delete[] users;
}

void Kindle::copyFrom(const Kindle &other) {
    booksCount = other.booksCount;
    booksCapacity = other.booksCapacity;

    books = new Book[booksCapacity];
    for (int i = 0; i < booksCount; ++i) {
        books[i] = other.books[i];
    }

    usersCount = other.usersCount;
    usersCapacity = other.usersCapacity;

    users = new User[usersCapacity];
    for (int i = 0; i < usersCount; ++i) {
        users[i] = other.users[i];
    }
}

void Kindle::addUser(const char *name, const char *password) {
    if (usersCount >= usersCapacity) {//resize:
        usersCapacity *= 2;

        User *temp = new User[usersCapacity];
        for (int i = 0; i < usersCount; ++i) {
            temp[i] = users[i];
        }

        delete[] users;
        users = temp;
    }

    users[usersCount++] = User(name, password);

    saveUsers();
}

void Kindle::save() const {
    saveBooks();
    saveUsers();
}

void Kindle::saveUsers() const {
    std::ofstream writeFile(USERS_FILE);

    writeFile << usersCount << DELIMITER;

    for (int i = 0; i < usersCount; ++i) {
        users[i].writeToFile(writeFile);
    }

    writeFile.close();
}

void Kindle::saveBooks() const {
    std::ofstream writeFile(BOOKS_FILE);

    writeFile << booksCount << DELIMITER;

    for (int i = 0; i < booksCount; ++i) {
        books[i].writeToFile(writeFile);
    }

    writeFile.close();
}

const User *Kindle::getUser(const char *name) const {
    for (int i = 0; i < usersCount; ++i) {
        if (strcmp(users[i].getName().c_str(), name) == 0) {
            return &users[i];
        }
    }

    return nullptr;
}

User *Kindle::copyUser(const char *name) const {
    const User *user = getUser(name);

    if (user == nullptr)
        return nullptr;

    return new User(*user);
}

void Kindle::printBooks() const {
    if (booksCount == 0) {
        std::cout << TAB << "No books to show!" << std::endl;
        return;
    }

    for (int i = 0; i < booksCount; ++i) {
        std::cout << TAB << i + 1 << ". ";
        std::cout << books[i].getTitle() << " by " << books[i].getAuthor() << std::endl;
    }
}

void Kindle::addBook(const Book &book) {
    if (booksCount >= booksCapacity) { //resize:
        booksCapacity *= 2;

        Book *temp = new Book[booksCapacity];
        for (int i = 0; i < booksCount; ++i) {
            temp[i] = books[i];
        }

        delete[] books;
        books = temp;
    }

    books[booksCount++] = book;

    book.writePages();

    saveBooks();
}

const Book *Kindle::getBook(const char *title) const {
    for (int i = 0; i < booksCount; ++i) {
        if (strcmp(books[i].getTitle().c_str(), title) == 0)
            return &books[i];
    }
    return nullptr;
}

int Kindle::getBooksCount() const {
    return booksCount;
}

void Kindle::updateUser(const User &user) {
    User *toUpdate = findUser(user.getName().c_str());

    *toUpdate = user;

    saveUsers();
}

User *Kindle::findUser(const char *name) {
    for (int i = 0; i < usersCount; ++i) {
        if (strcmp(users[i].getName().c_str(), name) == 0) {
            return &users[i];
        }
    }

    return nullptr;
}

Book *Kindle::findBook(const char *title) {
    for (int i = 0; i < booksCount; ++i) {
        if (strcmp(books[i].getTitle().c_str(), title) == 0)
            return &books[i];
    }
    return nullptr;
}

Book *Kindle::findBook(unsigned int id) {
    for (int i = 0; i < booksCount; ++i) {
        if (books[i].getId() == id)
            return &books[i];
    }

    return nullptr;
}

void Kindle::insertPageToBook(unsigned bookId, const Page &page) {
    //todo:
}

bool Kindle::changeTitle(unsigned int bookId, const String &title) {
    Book *toChange = findBook(bookId);

    if (toChange == nullptr)
        return false;

    toChange->setTitle(title);
    saveBooks();
    return true;
}

void Kindle::addPageToBook(unsigned int bookId, const Page &page) {
    Book *toUpdate = findBook(bookId);

    if (toUpdate == nullptr)
        return;

    toUpdate->addPage(page);

    toUpdate->writePages();
    saveBooks();
}

bool Kindle::editPageOfBook(unsigned int bookId, int pageNumber, const Page &page) {
    Book *toUpdate = findBook(bookId);

    if (toUpdate == nullptr)
        return false;

    toUpdate->setPage(pageNumber, page);
    toUpdate->writePages();
}

bool Kindle::rateBook(unsigned int bookId, int rateValue, const String &authorName) {
    Book *toChange = findBook(bookId);

    if (toChange == nullptr)
        return false;

    toChange->addRate(rateValue, authorName);

    saveBooks();
    return true;
}

bool Kindle::commentBook(unsigned int bookId, const String &text, const String &authorName) {
    Book *toComment = findBook(bookId);

    if (toComment == nullptr)
        return false;

    toComment->addComment(text, authorName);

    saveBooks();
    return true;
}



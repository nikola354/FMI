//
// Created by nikola354 on 01.05.22.
//

#include "Book.h"

Book::Book() {
    id = 0;
    pagesCount = 0;
    pagesCapacity = 1;
    pages = new Page[1];
    commentsCount = 0;
    ratesCount = 0;
}

Book::Book(const Book &other) {
    copyFrom(other);
}

Book &Book::operator=(const Book &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Book::~Book() {
    free();
}

Book::Book(std::ifstream &booksFile) {
    char buffer[FILE_BUFFER_SIZE];

    //id:
    booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    id = toNumber(buffer);

    //title:
    booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    title = buffer;

    //authorId:
    booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    author = buffer;

    //pagesCount:
    booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    pagesCount = toNumber(buffer);

    //commentsCount:
    booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    commentsCount = toNumber(buffer);

    char text[FILE_BUFFER_SIZE];
    for (int i = 0; i < commentsCount; ++i) {
        //author:
        booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);

        //text:
        booksFile.getline(text, FILE_BUFFER_SIZE, DELIMITER);

        comments[i] = Comment(text, buffer);
    }

    //ratesCount:
    booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    ratesCount = toNumber(buffer);

    for (int i = 0; i < ratesCount; ++i) {
        //author:
        booksFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);

        //value:
        booksFile.getline(text, FILE_BUFFER_SIZE, DELIMITER);
        int value = toNumber(text);

        rates[i] = Rate(value, buffer);
    }

    //fill pages:
    std::ifstream readFile(generateFileName().c_str());

    if (!readFile.is_open()) {
        throw "Error opening file!";
    }

    pagesCapacity = pagesCount;
    pages = new Page[pagesCapacity];
    for (int i = 0; i < pagesCount; ++i) {
        pages[i] = Page(readFile);
    }

    readFile.close();
}

Book::Book(int id, const char *title, const char *author, int pagesCount) {
    this->id = id;

    this->title = title;

    this->author = author;

    this->pagesCount = pagesCount;

    pagesCapacity = pagesCount + 1;
    pages = new Page[pagesCapacity];

    commentsCount = 0;
    ratesCount = 0;
}

void Book::free() {
    delete[] pages;
}

void Book::copyFrom(const Book &other) {
    id = other.id;

    title = other.title;

    author = other.author;

    pagesCount = other.pagesCount;
    pagesCapacity = other.pagesCapacity;

    pages = new Page[pagesCapacity];
    for (int i = 0; i < pagesCount; ++i) {
        pages[i] = other.pages[i];
    }

    commentsCount = other.commentsCount;
    for (int i = 0; i < commentsCount; ++i) {
        comments[i] = other.comments[i];
    }

    ratesCount = other.ratesCount;
    for (int i = 0; i < ratesCount; ++i) {
        rates[i] = other.rates[i];
    }
}

void Book::writeToFile(std::ofstream &writeFile) const {
    writeFile << id << DELIMITER;
    writeFile << title << DELIMITER;
    writeFile << author << DELIMITER;
    writeFile << pagesCount << DELIMITER;
    writeFile << commentsCount << DELIMITER;

    for (int i = 0; i < commentsCount; ++i) {
        writeFile << comments[i].getAuthor() << DELIMITER;
        writeFile << comments[i].getText() << DELIMITER;
    }

    writeFile << ratesCount << DELIMITER;

    for (int i = 0; i < ratesCount; ++i) {
        writeFile << rates[i].getAuthor() << DELIMITER;
        writeFile << rates[i].getValue() << DELIMITER;
    }
}

String Book::getTitle() const {
    return title;
}

String Book::getAuthor() const {
    return author;
}

void Book::addPage(const Page &p) {
    if (pagesCount >= pagesCapacity) { //resize:
        pagesCapacity *= 2;

        Page *temp = new Page[pagesCapacity];
        for (int i = 0; i < pagesCount; ++i) {
            temp[i] = pages[i];
        }

        delete[] pages;
        pages = temp;
    }

    pages[pagesCount++] = p;
}

String Book::generateFileName() const {
    String result = String(toStr(id));
    result.concat(String(BOOK_FILE_FORMAT));
    return result;
}

void Book::writePages() const {
    std::ofstream writeFile(generateFileName().c_str());

    for (int i = 0; i < pagesCount; ++i) {
        pages[i].writeToFile(writeFile);
    }

    writeFile.close();
}

const Page &Book::getPage(int index) const {
    if (index >= pagesCount)
        throw "Too big index";

    return pages[index];
}

int Book::getPagesCount() const {
    return pagesCount;
}

unsigned Book::getId() const {
    return id;
}

void Book::setTitle(const String &title) {
    this->title = title;
}

void Book::setPage(int index, const Page &page) {
    if (index >= pagesCount)
        return;

    pages[index] = page;
}

void Book::addRate(int rateValue, const String &authorName) {
    Rate *exising = findRate(authorName);

    if (exising != nullptr) { //rate already exists -> edit
        *exising = Rate(rateValue, authorName);
    } else {
        if (ratesCount >= MAX_RATES_COUNT)
            throw "Exceeded memory";

        rates[ratesCount++] = Rate(rateValue, authorName);
    }
}

Rate *Book::findRate(const String &authorName) {
    for (int i = 0; i < ratesCount; ++i) {
        if (rates[i].getAuthor() == authorName) {
            return &rates[i];
        }
    }
    return nullptr;
}

int Book::getRatesCount() const {
    return ratesCount;
}

void Book::printRates() const {
    using std::cout;
    using std::endl;

    if (ratesCount == 0) {
        cout << "No rates to show!" << endl;
    } else {
        for (int i = 0; i < ratesCount; ++i) {
            cout << rates[i] << endl;
        }

        cout << "Average rating: " << calcRating() << endl;
    }
}

void Book::printComments() const {
    using std::cout;
    using std::endl;

    if (commentsCount == 0) {
        cout << "No comments to show!" << endl;
    } else {
        for (int i = 0; i < commentsCount; ++i) {
            bool isBookAuthor = this->author == comments[i].getAuthor();
            comments[i].print(isBookAuthor);
        }
    }
}

double Book::calcRating() const {
    double result = 0;
    for (int i = 0; i < ratesCount; ++i) {
        result += rates[i].getValue();
    }
    result /= ratesCount;
    return result;
}

void Book::addComment(const String &comment, const String &authorName) {
    if (commentsCount >= MAX_COMMENTS_COUNT)
        throw "Exceeded memory";

    comments[commentsCount++] = Comment(comment, authorName);
}

//
// Created by nikola354 on 01.05.22.
//

#include "Book.h"

Book::Book() {
    id = 0;
    pagesCount = 0;
    pagesCapacity = 1;
    pages = new Page*[pagesCapacity];
    *pages = new Page();
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

Book::Book(int id, const char *title, const char *author, int pagesCount) {
    this->id = id;

    this->title = title;

    this->author = author;

    this->pagesCount = pagesCount;

    pagesCapacity = closestPowerOfTwo(pagesCount);
    pages = new Page*[pagesCapacity];

    commentsCount = 0;
    ratesCount = 0;
}

void Book::free() {
    for (int i = 0; i < pagesCount; ++i) {
        delete pages[i];
    }
    delete[] pages;
}

void Book::copyFrom(const Book &other) {
    id = other.id;

    title = other.title;

    author = other.author;

    pagesCount = other.pagesCount;
    pagesCapacity = other.pagesCapacity;

    pages = new Page*[pagesCapacity];
    for (int i = 0; i < pagesCount; ++i) {
        pages[i] = new Page(*other.pages[i]);
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
    writeFile.write((const char *) &id, sizeof(id));

    title.writeToFile(writeFile);
    author.writeToFile(writeFile);

    writeFile.write((const char *) &pagesCount, sizeof(pagesCount));
    for (int i = 0; i < pagesCount; ++i) {
        pages[i]->writeToFile(writeFile);
    }

    writeFile.write((const char *) &commentsCount, sizeof(commentsCount));
    for (int i = 0; i < commentsCount; ++i) {
        comments[i].writeToFile(writeFile);
    }

    writeFile.write((const char *) &ratesCount, sizeof(ratesCount));
    for (int i = 0; i < ratesCount; ++i) {
        rates[i].writeToFile(writeFile);
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

        Page **temp = new Page*[pagesCapacity];
        for (int i = 0; i < pagesCount; ++i) {
            temp[i] = new Page(*pages[i]);
        }

        free();
        pages = temp;
    }

    pages[pagesCount++] = new Page(p);
}

const Page &Book::getPage(int index) const {
    if (index >= pagesCount)
        throw "Too big index";

    return *pages[index];
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

    *pages[index] = page;
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

void Book::readFromFile(std::ifstream &readFile) {
    if (!readFile.is_open()) {
        throw "Error loading file!";
    }

    free(); //clear default data

    readFile.read((char *) &id, sizeof(id));

    title.readFromFile(readFile);
    author.readFromFile(readFile);

    readFile.read((char *) &pagesCount, sizeof(pagesCount));
    pagesCapacity = closestPowerOfTwo(pagesCount);

    pages = new Page*[pagesCapacity];
    for (int i = 0; i < pagesCount; ++i) {
        pages[i] = new Page();
        pages[i]->readFromFile(readFile);
    }

    readFile.read((char *) &commentsCount, sizeof(commentsCount));
    for (int i = 0; i < commentsCount; ++i) {
        comments[i].readFromFile(readFile);
    }

    readFile.read((char *) &ratesCount, sizeof(ratesCount));
    for (int i = 0; i < ratesCount; ++i) {
        rates[i].readFromFile(readFile);
    }
}

void Book::deletePage(int pageNum) {
    if (pageNum < 0 || pageNum >= pagesCount)
        throw "Could not delete page!";

    for (int i = pageNum; i < pagesCount - 1; ++i) {
        pages[i] = pages[i + 1];
    }

    pages[pagesCount - 1] = nullptr;
    pagesCount--;
}

void Book::insertPage(int pageNum, const Page &page) {
    if (pageNum < 0 || pageNum > pagesCount)
        return;

    if (pageNum == pagesCount) {
        addPage(page);
    } else {
        if (pagesCount >= pagesCapacity) {//resize:
            pagesCapacity *= 2;

            Page **temp = new Page*[pagesCapacity];
            for (int i = 0; i < pagesCount; ++i) {
                temp[i] = new Page(*pages[i]);
            }

            free();
            pages = temp;
        }

        pages[pagesCount] = new Page();
        for (int i = pagesCount; i > pageNum; --i) {
            pages[i] = pages[i - 1];
        }
        *pages[pageNum] = page;

        pagesCount++;
    }
}

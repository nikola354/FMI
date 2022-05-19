//
// Created by nikola354 on 02.05.22.
//

#include "menu.h"

using std::cout;
using std::cin;
using std::endl;

void loadMenu(Kindle &k) {
    User auth = User();

    while (true) {
        char buffer[CONSOLE_BUFFER_SIZE] = {};

        cout << "Enter a command:" << endl;
        cin.getline(buffer, CONSOLE_BUFFER_SIZE);
        String command = String();
        command = String(buffer);
        command.trim();

        if (strcmp(command.c_str(), SIGNUP_CMD) == 0) {
            signUp(k, auth);
        } else if (strcmp(command.c_str(), LOGIN_CMD) == 0) {
            login(k, auth);
        } else if (strcmp(command.c_str(), LOGOUT_CMD) == 0) {
            if (auth.getName().getSize() == 0) {
                cout << "You must first log in!" << endl;
                continue;
            }
            auth = User();
            cout << "Logged out!" << endl;
        } else if (strcmp(command.c_str(), VIEW_CMD) == 0) {
            k.printBooks();
        } else if (strcmp(command.c_str(), WRITE_CMD) == 0) {
            if (auth.getName().getSize() == 0) {
                cout << "You must first log in!" << endl;
                continue;
            }
            writeBook(k, auth);
        } else { //MULTIPLE WORDS COMMANDS:
            String *first = command.popNextWord();

            if (strcmp(first->c_str(), READ_CMD) == 0) {
                if (auth.getName().getSize() == 0) {
                    cout << "You must first log in!" << endl;
                    continue;
                }
                readBook(k, auth, command);

            } else if (strcmp(first->c_str(), EDIT_CMD) == 0) {
                if (auth.getName().getSize() == 0) {
                    cout << "You must first log in!" << endl;
                    continue;
                }
                editBook(k, auth, command);
            } else if (strcmp(first->c_str(), RATE_CMD) == 0) {
                if (auth.getName().getSize() == 0) {
                    cout << "You must first log in!" << endl;
                    continue;
                }

                String *title = command.popNextWord();

                if (*title->c_str() == TERMINATE_SYMBOL || *command.c_str() == TERMINATE_SYMBOL) {
                    cout << "Missing parameters! You must enter rate <title> <rate_value>." << endl;
                    continue;
                }

                if (!isNumber(command.c_str())) {
                    cout << "The rate value must be a number!" << endl;
                    continue;
                }

                rateBook(k, auth, *title, toNumber(command.c_str()));
                delete title;
            } else if (strcmp(first->c_str(), VIEW_RATES_CMD) == 0) {
                if (auth.getName().getSize() == 0) {
                    cout << "You must first log in!" << endl;
                    continue;
                }

                printRates(k, command);
            } else if (strcmp(first->c_str(), COMMENT_CMD) == 0) {
                if (auth.getName().getSize() == 0) {
                    cout << "You must first log in!" << endl;
                    continue;
                }

                String *title = command.popNextWord();

                if (*title->c_str() == TERMINATE_SYMBOL || *command.c_str() == TERMINATE_SYMBOL) {
                    cout << "Missing parameters! You must enter comment <title> <comment_text>." << endl;
                    continue;
                }

                commentBook(k, auth, *title, command);
                delete title;
            } else if (strcmp(first->c_str(), VIEW_COMMENTS_CMD) == 0) {
                if (auth.getName().getSize() == 0) {
                    cout << "You must first log in!" << endl;
                    continue;
                }

                printComments(k, command);
            } else {
                cout << "Wrong command! Try again..." << endl;
            }
            delete first;
        }
    }
}

void printComments(Kindle &k, const String &title) {
    const Book *book = k.getBook(title);

    if (book == nullptr) {
        cout << "There is no book with this title!" << endl;
        return;
    }

    book->printComments();
}

void commentBook(Kindle &k, User &auth, const String &title, const String &comment) {
    const Book *book = k.getBook(title);

    if (book == nullptr) {
        cout << "There is no book with this title!" << endl;
        return;
    }

    bool isAuthor = book->getAuthor() == auth.getName();

    if (!isAuthor && !auth.hasReadBook(*book)) {
        cout << "You must read the book first! Use: " << READ_CMD << " " << book->getTitle() << endl;
        return;
    }

    if (k.commentBook(book->getId(), String(comment), auth.getName())) {
        cout << "Comment added successfully!" << endl;
    } else {
        cout << "Something went wrong!" << endl;
    }
}

void printRates(Kindle &k, const String &title) {
    const Book *book = k.getBook(title);

    if (book == nullptr) {
        cout << "There is no book with this title!" << endl;
        return;
    }

    book->printRates();
}

void rateBook(Kindle &k, User &auth, const String &title, int rate) {
    const Book *book = k.getBook(title);

    if (book == nullptr) {
        cout << "There is no book with this title!" << endl;
        return;
    }

    if (book->getAuthor() == auth.getName()) {
        cout << "You cannot rate your own book!" << endl;
        return;
    }

    if (!auth.hasReadBook(*book)) {
        cout << "You must read the book first! Use: " << READ_CMD << " " << book->getTitle() << endl;
        return;
    }

    if (rate < MIN_RATE || rate > MAX_RATE) {
        cout << "You must rate the book between " << MIN_RATE << " and " << MAX_RATE << endl;
        return;
    }

    int ratesBefore = book->getRatesCount();
    if (k.rateBook(book->getId(), rate, auth.getName())) {
        if (ratesBefore < book->getRatesCount()) {
            cout << "Rate added successfully!" << endl;
        } else {
            cout << "You already rated this book. Your rate was changed to " << rate << "!" << endl;
        }
    } else {
        cout << "Something went wrong!" << endl;
    }
}

void insertPage(Kindle &k, const Book &book) {
    while (true) {
        cout << "Enter index (between 1 and "<< book.getPagesCount() + 1 << "):" << endl;

        char input[CONSOLE_BUFFER_SIZE];
        cin.getline(input, CONSOLE_BUFFER_SIZE);

        if (!isNumber(input)) {
            cout << "You must enter a number!" << endl;
            continue;
        }

        int index = toNumber(input) - 1;
        if (index < 0){
            cout << "If you want to insert a page before the first one, enter 1" << endl;
            continue;
        }

        if (index > book.getPagesCount()) {
            cout << "The book does not have so many pages!" << endl;
            continue;
        }

        cout << "Enter the content of the page and enter " << QUIT_CMD
             << " on a new line when the page is finished!" << endl;

        Page page;

        while (true) {
            char line[LINE_BUFFER_SIZE];
            cin.getline(line, LINE_BUFFER_SIZE);

            if (strcmp(line, QUIT_CMD) == 0) {
                break;
            }

            page.addLine(String(line));
        }

        if (k.insertPageToBook(book.getId(), page, index)) {
            cout << "Page inserted successfully!" << endl;
        } else {
            cout << "Something went wrong!" << endl;
        }
        return;
    }
}

void addPage(Kindle &k, const Book &book) {
    cout << "Enter the content of the page and enter " << QUIT_CMD
         << " on a new line when the page is finished!" << endl;

    Page page;

    while (true) {
        char line[LINE_BUFFER_SIZE];
        cin.getline(line, LINE_BUFFER_SIZE);

        if (strcmp(line, QUIT_CMD) == 0) {
            break;
        }

        page.addLine(String(line));
    }

    k.addPageToBook(book.getId(), page);

    cout << "Successfully added one page!" << endl;
}

void changeTitle(Kindle &k, const Book &book) {
    cout << "Enter the new title of the book:" << endl;
    char title[CONSOLE_BUFFER_SIZE];
    cin.getline(title, CONSOLE_BUFFER_SIZE);

    const Book *existingBook = k.getBook(title);
    if (existingBook != nullptr) {
        cout << "There is already a book with this title!" << endl;
        return;
    }

    if (k.changeTitle(book.getId(), String(title)))
        cout << "Title successfully changed!" << endl;
    else
        cout << "Something went wrong!" << endl;
}

void editPage(Kindle &k, const Book &book, int pageNumber) {
    cout << "Enter the new content of the page:" << endl;

    Page page;
    while (true) {
        char line[LINE_BUFFER_SIZE];
        cin.getline(line, LINE_BUFFER_SIZE);

        if (strcmp(line, QUIT_CMD) == 0) {
            break;
        }

        page.addLine(String(line));
    }

    if (k.editPageOfBook(book.getId(), pageNumber, page))
        cout << "Page successfully changed!" << endl;
    else
        cout << "Something went wrong!" << endl;
}

void editPageMenu(Kindle &k, const Book &book) {
    bool ready;
    do {
        ready = true;

        cout << "Enter the page number (pages start from 1):" << endl;
        int number;
        cin >> number;
        number--;

        if (number < 0) {
            cout << "Pages start from 1!" << endl;
            ready = false;
            continue;
        }

        if (number >= book.getPagesCount()) {
            cout << "The book does not have so many pages!" << endl;
            ready = false;
            continue;
        }

        cout << "Page #" << number + 1 << ":" << endl;
        book.getPage(number).print();

        editPage(k, book, number);

    } while (!ready);

}

bool askIfSureToDelete(int pageNum) {
    cout << "Are you sure you want to delete the page #" << pageNum + 1<< "? This action cannot be reversed!" << endl;

    char input[CONSOLE_BUFFER_SIZE];
    cin.getline(input, CONSOLE_BUFFER_SIZE);

    String answer = String(input);
    answer.trim();

    while (true) {
        if (strcasecmp(answer.c_str(), "yes") == 0 || strcasecmp(answer.c_str(), "y") == 0 ||
            strcasecmp(answer.c_str(), "!yes") == 0)
            return true;
        else if (strcasecmp(answer.c_str(), "no") == 0 || strcasecmp(answer.c_str(), "n") == 0 ||
                 strcasecmp(answer.c_str(), "!no") == 0)
            return false;

        cout << "Your answer was not clear for us :( Please type yes or no:" << endl;
    }
}

void deletePage(Kindle &k, const Book &book) {
    while (true) {
        cout << "Enter the number of the page you want to delete (between 1 and " << book.getPagesCount() << ") or q to go back:" << endl;

        char input[CONSOLE_BUFFER_SIZE];
        cin.getline(input, CONSOLE_BUFFER_SIZE);

        if (strcmp(input, Q_CMD) == 0) {
            return;
        }

        if (!isNumber(input)) {
            cout << "You must enter a number!" << endl;
            continue;
        }

        int pageNum = toNumber(input) - 1;

        if (pageNum >= book.getPagesCount()) {
            cout << "The book does not have so many pages!" << endl;
            continue;
        }

        if (askIfSureToDelete(pageNum)) {
            if (k.deletePageFromBook(book.getId(), pageNum)) {
                cout << "Successfully deleted page #" << pageNum + 1 << "!" << endl;
            } else {
                cout << "Something went wrong!" << endl;
            }
        }
        return;
    }
}

void editBook(Kindle &k, User &auth, const String &title) {
    const Book *book = k.getBook(title);

    if (book == nullptr) {
        cout << "Wrong title of the book!" << endl;
        return;
    }

    if (auth.getName() != book->getAuthor()) {
        cout << "Only the author of the book can edit!" << endl;
        return;
    }

    while (true) {
        cout << "Enter a number: " << endl;
        cout << "0. Exit edit mode" << endl;
        cout << "1. Add page at the end" << endl;
        cout << "2. Insert page at a specific position (starting from 1)" << endl;
        cout << "3. Delete last page" << endl;
        cout << "4. Delete page at a specific position (starting from 1)" << endl;
        cout << "5. Edit a page" << endl;
        cout << "6. Change title of the book" << endl;

        char input[CONSOLE_BUFFER_SIZE];
        cin.getline(input, CONSOLE_BUFFER_SIZE);
        int command = toNumber(input);

        switch (command) {
            case 0:
                return;
            case 1:
                addPage(k, *book);
                break;
            case 2:
                insertPage(k, *book);
                break;
            case 3:
                if (askIfSureToDelete(book->getPagesCount() - 1)) {
                    if (k.deletePageFromBook(book->getId(), book->getPagesCount() - 1)) {
                        cout << "Last page deleted successfully!" << endl;
                    } else {
                        cout << "Something went wrong!" << endl;
                    }
                }
                break;
            case 4:
                deletePage(k, *book);
                break;
            case 5:
                editPageMenu(k, *book);
                break;
            case 6:
                changeTitle(k, *book);
                break;
            default:
                cout << "Wrong command!" << endl;
        }
    }
}

void readBook(Kindle &k, User &auth, const String &title) {
    const Book *book = k.getBook(title);

    if (book == nullptr) {
        cout << "Wrong title of the book!" << endl;
        return;
    }

    bool isAuthor = (auth.getName() == book->getAuthor());

    if (!isAuthor && !auth.hasReadBook(*book)) {
        auth.readBook(*book);
        k.updateUser(auth);
    }

    if (book->getPagesCount() == 0) {
        cout << "This book has no pages yet!" << endl;
        return;
    }

    int pageNum = 0;
    cout << "Page " << pageNum + 1 << ":" << endl;
    book->getPage(pageNum).print();

    while (true) {
        cout << "Enter command: " << endl;
        cout << NEXT_CMD << " -> next page; " << endl;
        cout << PREV_CMD << " -> previous page; " << endl;
        if (isAuthor)
            cout << EDIT_CMD << " -> edit current page; " << endl;
        cout << "number -> go to specific page; " << endl;
        cout << Q_CMD << " -> quit reading" << endl;

        char command[CONSOLE_BUFFER_SIZE];
        cin.getline(command, CONSOLE_BUFFER_SIZE);

        if (strcmp(command, Q_CMD) == 0)
            return;

        if (strcmp(command, NEXT_CMD) == 0) {
            if (pageNum + 1 < book->getPagesCount()) {
                pageNum++;
            }
        } else if (strcmp(command, PREV_CMD) == 0) {
            if (pageNum > 0) {
                pageNum--;
            }
        } else if (isAuthor && strcmp(command, EDIT_CMD) == 0) {
            editPage(k, *book, pageNum);
        } else if (isNumber(command)) {
            int wishedPage = toNumber(command) - 1; //we count from 0
            if (wishedPage >= book->getPagesCount()) {
                cout << "The book does not have so many pages!" << endl;
                continue;
            }
            pageNum = wishedPage;
        } else {
            cout << "Wrong command!" << endl;
            continue;
        }

        cout << "Page " << pageNum + 1 << ":" << endl;
        book->getPage(pageNum).print();
    }
}

void writeBook(Kindle &k, User &auth) {
    bool ready;
    do {
        ready = true;

        cout << "Enter title:" << endl;

        char title[CONSOLE_BUFFER_SIZE];
        cin.getline(title, CONSOLE_BUFFER_SIZE);

        //check for unique title
        if (k.getBook(title) != nullptr) {
            cout << "There is a book with this title already!" << endl;
            ready = false;
            continue;
        }

        //pagesCount:
        cout << "Enter pages count:" << endl;
        char buffer[CONSOLE_BUFFER_SIZE];
        cin.getline(buffer, CONSOLE_BUFFER_SIZE);

        if (!isNumber(buffer)) {
            cout << "You must enter a number!" << endl;
            ready = false;
            continue;
        }

        int pagesCount = toNumber(buffer);

        Book newBook = Book(k.getBooksCount(), title, auth.getName().c_str(), 0);

        for (int i = 0; i < pagesCount; ++i) {
            cout << "Enter the content of page #" << i + 1 << " and enter " << QUIT_CMD
                 << " on a new line when the page is finished!" << endl;

            Page page;

            while (true) {
                char line[LINE_BUFFER_SIZE];
                cin.getline(line, LINE_BUFFER_SIZE);

                if (strcmp(line, QUIT_CMD) == 0) {
                    break;
                }

                page.addLine(String(line));
            }

            newBook.addPage(page);
        }

        k.addBook(newBook);
    } while (!ready);
}

void signUp(Kindle &k, User &auth) {
    if (auth.getName().getSize() != 0) {
        cout << "You are already logged in!" << endl;
        return;
    }

    bool ready;
    do {
        ready = true;

        cout << "Enter username:" << endl;
        char name[CONSOLE_BUFFER_SIZE];
        cin.getline(name, CONSOLE_BUFFER_SIZE);

        if (!checkName(name)) {
            cout << "The name must be between " << MIN_NAME_LENGTH << " and " << MAX_NAME_LENGTH
                 << " characters long!"
                 << endl;
            ready = false;
            continue;
        }

        if (k.getUser(name) != nullptr) {
            cout << "This username is already taken!" << endl;
            ready = false;
            continue;
        }

        cout << "Enter password:" << endl;
        char password[CONSOLE_BUFFER_SIZE];
        cin.getline(password, CONSOLE_BUFFER_SIZE);

        if (!checkPassword(password)) {
            cout << "The password must be between " << MIN_PASS_LENGTH << " and " << MAX_PASS_LENGTH
                 << " characters long!" << endl;
            ready = false;
            continue;
        }

        k.addUser(name, password);

        auth = *k.copyUser(name);

        cout << TAB << "User registered!" << endl;

    } while (!ready);
}

void login(Kindle &k, User &auth) {
    if (auth.getName().getSize() != 0) {
        cout << "You are already logged in!" << endl;
        return;
    }

    bool ready;
    do {
        ready = true;

        cout << "Enter username or type 0 to go back:" << endl;
        char name[CONSOLE_BUFFER_SIZE];
        cin.getline(name, CONSOLE_BUFFER_SIZE);

        if (strcmp(name, "0") == 0)
            return;

        const User *user = k.getUser(name);

        if (user == nullptr) {
            cout << "User not found! Try again..." << endl;
            ready = false;
            continue;
        }

        cout << "Enter password or type 0 to go back:" << endl;
        char password[CONSOLE_BUFFER_SIZE];
        cin.getline(password, CONSOLE_BUFFER_SIZE);

        if (strcmp(password, "0") == 0)
            return;

        if (strcmp(user->getPassword().c_str(), password) != 0) {
            cout << "Wrong password!" << endl;
            ready = false;
            continue;
        }

        auth = User(*user);

        cout << TAB << "Welcome, " << name << "!" << endl;
    } while (!ready);
}


#include <iostream>
#include <sstream>
#include <charconv>

#include "menu.h"

#include "Comment.h"
#include "String.h"

int main() {
    //todo: by adding user do not update the whole file but only the counter and the user
    //todo: do not need to say how many pages when writing a book

    try{
        Kindle k;

        loadMenu(k);
    }catch (const char * item) {
        std::cout << item << std::endl;
    }

    return 0;
}
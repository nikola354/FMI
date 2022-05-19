#include <iostream>

#include "menu.h"

int main() {
    try{
        Kindle k;

        loadMenu(k);
    }catch (const char * item) {
        std::cout << item << std::endl;
    }

    return 0;
}
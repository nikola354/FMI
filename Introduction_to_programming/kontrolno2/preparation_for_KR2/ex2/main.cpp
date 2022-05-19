/*
 * 2. **Задача**. Да се напише функция, която по дадено число в интервала 0-86000, го интерпретира като брой секунди от началото на деня и
 * връща като резултат часа във формат HH:MM. Да се напише програма,
 * която използва написаната функция, за да въведе от конзолата цяло число,
 * и по него да изчисли и изведе часа във формат HH:MM.
 *
 * */

#include <iostream>

//Line 1-8 are included in all .cpp files to check for memory leaks

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif



using namespace std;

const int MAX_SECONDS = 86000;
const int SECONDS_PER_MINUTE = 60;
const int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * 60;

char formatTime(int seconds){
    if (seconds < 0 || seconds > MAX_SECONDS){
        return '1';
    }

    int hours = 0;
    while (seconds > SECONDS_PER_HOUR){
        hours++;
        seconds -= SECONDS_PER_HOUR;
    }

    return '5';
}

int main() {
//    CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); //first line in main function


    cout << formatTime(888);

    return 0;
}

#include <iostream>

using namespace std;

int strLength(const char *str){
    int length = 0;

    while (*str++ != '\0'){
        length++;
    }
    return length;
}

int strLength2(const char *str){
    int length = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        length++;
    }
    return length;
}

int main() {
//    int arr[3] = {5, 10 ,15};
//
//    int *p = &arr[1];
//
//    cout << *p << endl;
//
//    p++;
//
//    cout << *p << endl;

    char str[] = "abc";

    char *ptr = &str[0];

    ptr++;

    cout << strLength(str) << endl;
    cout << str << endl;



    return 0;
}

void constantPointers(){
    const int a = 15;
    int b = 100;


}

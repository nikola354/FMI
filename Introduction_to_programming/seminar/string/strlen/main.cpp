#include <iostream>

using namespace std;

size_t my_strlen (const char* str){
    size_t length = 0;

    while (str[length] != '\0'){
        length++;
    }

    return length;
}

int min (size_t num1, size_t num2){
    return (num1 < num2 ? num1 : num2);
}

int my_strcmp (const char* str1, const char* str2){
    size_t str1Length = my_strlen(str1);
    size_t str2Length = my_strlen(str2);

    size_t smallerLength = min(str1Length, str2Length);

}

int main() {


    return 0;
}

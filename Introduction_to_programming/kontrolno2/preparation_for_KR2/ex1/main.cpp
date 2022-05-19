/**
 * 1. **Задача**.
 * Да се напише функция, която връща като резултат най-голямото число в предаден като параметър масив от естествени числа.
 * Да се напише програма, която използва написаната функция, за да въведе от конзолата масив от цели числа и да изведе най-голямото от тях.
 * */

#include <iostream>

using namespace std;

//void printArr(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//}
//
//void multiplyBy2 (int arr[], int size){
//    for (int i = 0; i < size; i++){
//        arr[i] *= 2;
//    }
//}

int getMax (int arr[], int size){
    int max = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}

int main() {
    int n;

    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] < 0){
            cout << "-1";
            return 0;
        }
    }

    int size = sizeof(arr) / sizeof(int);

    cout << getMax(arr, size);

}


#include <iostream>

using namespace std;

void order(int *arr, int size);

int main() {
    int n;
    cin >> n;

    int numbers[n];

    int index = 0;
    while(index < n){
        cin >> numbers[index];
        index++;
    }

    order(numbers, n);

    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << " ";
    }

    return 0;
}

void order(int *arr, int size){
    int *evenNumbers = new int[size];
    int *oddNumbers = new int[size];

    int evenIndex = 0;
    int oddIndex = 0;
    for (int i = 0; i < size; ++i) {
        if(arr[i] % 2 == 0){
            evenNumbers[evenIndex] = arr[i];
            evenIndex++;
        }else{
            oddNumbers[oddIndex] = arr[i];
            oddIndex++;
        }
    }

    delete[] arr;
    arr = new int[size];

    int evenLength = sizeof(*evenNumbers) / sizeof(int);
    int oddLength = sizeof(*oddNumbers) / sizeof(int);

    for (int j = 0; j < evenLength; ++j) {
        arr[j] = evenNumbers[j];
    }

    for (int k = 0; k < oddLength; ++k) {
        arr[evenLength + k] = oddNumbers[k];
    }

}
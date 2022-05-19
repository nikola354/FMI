/**
 @author Nikola Manolov
 @idnumber 5MI0600093
 @compiler GCC
 @IDE CLion
 @OS Linux
 * */

#include <iostream>

using namespace std;

unsigned long countSums(const long *arr1, unsigned arr1Length, const long *arr2, unsigned arr2Length, const long *arr3, unsigned arr3Length);
int main() {

    long arr1[] = {1, 5, 3};
    long arr2[] = {2, 4};
    long arr3[] = {6, 3, 0};

    unsigned long countedSums = countSums(arr1, 3, arr2, 2, arr3, 3);

    cout << countedSums << endl;

    return 0;
}

unsigned long countSums(const long *arr1, unsigned arr1Length, const long *arr2, unsigned arr2Length, const long *arr3, unsigned arr3Length){
    unsigned long counter = 0;

    for (int i = 0; i < arr1Length; ++i) {
        for (int j = 0; j < arr2Length; ++j) {
            for (int k = 0; k < arr3Length; ++k) {
                if (arr1[i] == arr2[j] + arr3[k] || arr2[j] == arr1[i] + arr3[k] || arr3[k] == arr1[i] + arr2[j]){
                    counter++;
                    cout << "(" << arr1[i] << ", " << arr2[j] << ", " << arr3[k] << ")" << endl;
                }
            }
        }
    }

    return counter;
}

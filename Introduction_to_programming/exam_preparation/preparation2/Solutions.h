// 5MI0600093 - Nikola Manolov
// Created by nikola354 on 25.01.22 г..
//

#ifndef PREPARATION2_SOLUTIONS_H
#define PREPARATION2_SOLUTIONS_H

void ConvertArr(long arr[], long S, long E) {
    if (S < 0 || E <= 0 || S >= E)
        return;

    long *temp = new long[E - S + 1];

    for (long i = S; i <= E; ++i) {
        temp[i - S] = arr[i];
    }

    for (long i = S; i <= E; ++i) {
        arr[i] = temp[E - i];
    }
}

#endif //PREPARATION2_SOLUTIONS_H

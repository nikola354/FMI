#include <iostream>
#include <fstream>

using namespace std;


unsigned closestPowerOfTwo(unsigned n) {
    unsigned count = 0;

    // First n in the below condition
    // is for the case where n is 0
    if (n && !(n & (n - 1)))
        return n;

    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }

    return 1 << count;
}

int main()
{
    cout << closestPowerOfTwo(0) << endl;
    cout << closestPowerOfTwo(4) << endl;
    cout << closestPowerOfTwo(5) << endl;
    cout << closestPowerOfTwo(33) << endl;
    cout << closestPowerOfTwo(1025) << endl;

}

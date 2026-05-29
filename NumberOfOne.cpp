#include <iostream>
#include <cmath>

int countDigitOne(int n) {
    if(n <= 0) return 0;
    if(n <= 9) return 1;
    int copy = n;
    int digits = 0;
    int count = 0;
    int nine = 0;
    while(copy > 0) {
        int r = copy%10;
        if(r == 1) count++;
        copy = copy/10;
        nine = nine*10 + 9;
        digits++;
    }

    if(n == nine) return digits * pow(10, digits-1);
    else return count + countDigitOne(n-1);
}

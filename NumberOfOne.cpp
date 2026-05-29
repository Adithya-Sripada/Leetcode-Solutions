#include <iostream>
#include <string>
#include <cmath>

int countDigitOne(int n) {
    if(n <= 0) return 0;
    if(n <= 9) return 1;
    int x = n;
    int digits = 0;
    int count = 0;
    while(x > 0) {
        int r = x%10;
        if(r == 1) count++;
        x = x/10;
        digits++;
    }

    std::string nine(digits, '9');
    if(std::to_string(n) == nine) return digits * pow(10, digits-1);
    else return count + countDigitOne(n-1);
}

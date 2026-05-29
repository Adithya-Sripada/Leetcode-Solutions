#include <iostream>
int countDigitOne(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int count = 0;
    int x = n;
    while(n > 0) {
        int r = n%10;
        if(r == 1) count++;
        n = n/10;
    }
    std::cout << count << "\n";
    return count + countDigitOne(x-1);
}

int main() {
    std::cout << countDigitOne(13);
}
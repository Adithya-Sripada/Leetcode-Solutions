class Solution {
public:
    double myPow(double x, int n) {
        if(n == -2147483648) {
            if(x > 1) return 0;
            else return 1;
        }
        else if(n < 0) {
            n = -n;
            x = 1/x;
        }
        if(n <= 0) return 1;
        if(n == 1) return x;
        if(n%2 == 0) return x * myPow(x, n-1);
        else return x * myPow(x*x, n/2);
    }
};

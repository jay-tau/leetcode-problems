class Solution {
public:
    double myPow(double x, int n) {
        if (n == -1) return (1 / x);
        if (n == 0) return 1;
        
        int mod = n % 2;
        mod = (mod < 1) ? (2 - mod) : mod;
        if (mod % 2 == 0) {
            double temp = myPow(x, n / 2);
            return temp*temp;
        } else {
            return (x * myPow(x, n-1));
        }
    }
};
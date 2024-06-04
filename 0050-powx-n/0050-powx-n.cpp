class Solution {
public:
    double myPow(double x, int n) {
        // -ve, positive, 0
        if (n == 0) return 1;
        
        if (n < 0)
            return (1 / x) * myPow(1/x, abs(n)-1); // -1 due to limit on positive side being lower
        
        // O(log n) time
        if (n % 2 == 0)
            return myPow(x*x, n/2);
        else
            return x * myPow(x, n-1);
    }
};
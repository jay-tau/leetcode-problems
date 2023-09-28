class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0)
      // return (1 / myPow(x, -n));
      return ((1 / x) * (1 / (myPow(x, -(n + 1)))));  // abs(INT_MAX) =
                                                      // INT_MAX+1 , leading to
                                                      // overflow
    if (n % 2 == 0)
      return myPow(x * x, n / 2);
    else
      return (x * myPow(x, n - 1));
  }
};
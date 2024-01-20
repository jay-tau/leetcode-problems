class Solution {
 public:
  int reverse(int x) {
    int x_rev = 0, x_copy = abs(x);

    while (x_copy > 0) {
      if (x_rev > (INT_MAX / 10)) return 0;
      x_rev *= 10;
      x_rev += (x_copy % 10);
      x_copy /= 10;
    }

    if (x < 0) x_rev *= -1;

    return x_rev;
  }
};
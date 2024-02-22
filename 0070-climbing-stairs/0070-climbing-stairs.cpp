class Solution {
 private:
  vector<int> memo;
  int dp(int i, const int n) {
    if (i > n) return 0;

    if (i == n) return 1; // Valid solution

    if (memo[i] != -1) return memo[i];

    return memo[i] = dp(i + 1, n) + dp(i + 2, n);
  }

 public:
  int climbStairs(int n) {
    memo.resize(n, -1);
    return dp(0, n);
  }
};
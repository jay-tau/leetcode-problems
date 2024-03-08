class Solution {
 private:
  vector<vector<int>> memo;
  int dp(int i, int j, string &s1, string &s2) {
    int n = s1.size(), m = s2.size();

    if ((i >= n) || (j >= m)) return 0;

    int &ans = memo[i][j];
    if (ans != -1) return ans;

    if (s1[i] == s2[j])
      ans = 1 + dp(i + 1, j + 1, s1, s2);
    else
      ans = max(dp(i + 1, j, s1, s2), dp(i, j + 1, s1, s2));

    return ans;
  }

 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();

    memo.resize(n, vector<int>(m, -1));

    return dp(0, 0, text1, text2);
  }
};
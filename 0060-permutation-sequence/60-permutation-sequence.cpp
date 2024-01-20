class Solution {
 private:
  vector<int> factorials;
  int factorial(int n) {
    if (factorials[n] != -1)  // If found in DP
      return factorials[n];

    if (n == 0) return factorials[0] = 1;
    return factorials[n] = n * factorial(n - 1);
  }

  void f(int n, int k, vector<int> &v, vector<int> &ans) {
    if (n == 0) return;

    // Write it as element*(n-1)! + r (where r > 0)
    int dr = factorial(n - 1);
    int element = (k % dr == 0) ? ((k / dr) - 1) : (k / dr);
    int r = (k % dr == 0) ? (dr) : (k % dr);  // Should be dr instead of 0

    ans.push_back(v[element]);
    v.erase(v.begin() + element);  // Erase v[element]

    f(n - 1, r, v, ans);
  }

 public:
  string getPermutation(int n, int k) {
    factorials.resize(n + 1, -1);  // To store [0, n] factorials

    vector<int> ans;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) v[i - 1] = i;

    f(n, k, v, ans);

    string s = "";
    for (auto x : ans) s += to_string(x);

    return s;
  }
};
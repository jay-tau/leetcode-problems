class Solution {
public:
  vector<vector<int>> dp{200, vector<int>(200, -1)};
  int f(int i, int j, vector<vector<int>> &v) {
    int n = v.size(), m = v[0].size();
    
    if ((i < 0) || (j < 0)) return INT_MAX;
    if ((i >= n) || (j >= m)) {cout << "Error in call\t" << i << "," << j << endl; return 0;}
    
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    
    if ((i == 0) && (j == 0)) return v[i][j];
    ans = v[i][j] + min(f(i-1, j, v), f(i, j-1, v));
    
    return ans;
  }
    int minPathSum(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid[0].size();
      int ans = f(n-1, m-1, grid);
      for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) { cout << dp[i][j] << " "; } cout << endl; }
      return ans;
    }
};
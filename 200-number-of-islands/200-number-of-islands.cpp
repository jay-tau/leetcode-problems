#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(int row, int col, int num_rows, int num_cols) {
    return (row >= 0 && row < num_rows && col >= 0 && col < num_cols);
  }

  void dfs(vector<vector<char>> &grid, int x, int y) {
    int num_rows = grid.size(), num_cols = grid[0].size();
    // Mark the current cell as visited
    grid[x][y] = '0';
    // Check all 4 directions
    if (isValid(x + 1, y, num_rows, num_cols) && grid[x + 1][y] == '1')
      dfs(grid, x + 1, y);
    if (isValid(x - 1, y, num_rows, num_cols) && grid[x - 1][y] == '1')
      dfs(grid, x - 1, y);
    if (isValid(x, y + 1, num_rows, num_cols) && grid[x][y + 1] == '1')
      dfs(grid, x, y + 1);
    if (isValid(x, y - 1, num_rows, num_cols) && grid[x][y - 1] == '1')
      dfs(grid, x, y - 1);
  }

  int numIslands(vector<vector<char>> &grid) {
    int num_rows = grid.size(), num_cols = grid[0].size();
    // Perform DFS from each cell with 1
    int num_islands = 0;
    for (int i = 0; i < num_rows; ++i) {
      for (int j = 0; j < num_cols; ++j) {
        if (grid[i][j] == '1') {
          ++num_islands;
          dfs(grid, i, j);
        }
      }
    }
    return num_islands;
  }
};
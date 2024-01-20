#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int x, int y, int rows, int cols) {
    return (((0 <= x) && (x < rows)) && ((0 <= y) && (y < cols)));
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    // Make boolean matrix pacific and atlantic
    int num_rows = heights.size(), num_cols = heights[0].size();

    queue<pair<int, int>> to_visit_pacific, to_visit_atlantic;
    vector<vector<bool>> visited_pacific(num_rows, vector<bool>(num_cols, 0));
    vector<vector<bool>> visited_atlantic(num_rows, vector<bool>(num_cols, 0));

    for (int i = 0; i < num_rows; ++i) { // Vertical border
      to_visit_pacific.push({i, 0});
      to_visit_atlantic.push({i, num_cols - 1});
    }
    for (int i = 0; i < num_cols; ++i) { // Horizontal border
      to_visit_pacific.push({0, i});
      to_visit_atlantic.push({num_rows - 1, i});
    }

    // Perform DFS from pacific border
    while (!to_visit_pacific.empty()) {
      pair<int, int> current_cell = to_visit_pacific.front();
      to_visit_pacific.pop();
      int x = current_cell.first, y = current_cell.second;
      int current_height = heights[x][y];

      if (visited_pacific[x][y])
        continue;

      visited_pacific[x][y] = true;

      if (isValid(x - 1, y, num_rows, num_cols) &&
          (heights[x - 1][y] >= current_height))
        to_visit_pacific.push({x - 1, y});
      if (isValid(x + 1, y, num_rows, num_cols) &&
          (heights[x + 1][y] >= current_height))
        to_visit_pacific.push({x + 1, y});
      if (isValid(x, y - 1, num_rows, num_cols) &&
          (heights[x][y - 1] >= current_height))
        to_visit_pacific.push({x, y - 1});
      if (isValid(x, y + 1, num_rows, num_cols) &&
          (heights[x][y + 1] >= current_height))
        to_visit_pacific.push({x, y + 1});
    }

    while (!to_visit_atlantic.empty()) {
      pair<int, int> current_cell = to_visit_atlantic.front();
      to_visit_atlantic.pop();
      int x = current_cell.first, y = current_cell.second;

      int current_height = heights[x][y];

      if (visited_atlantic[x][y])
        continue;

      visited_atlantic[x][y] = true;

      if (isValid(x - 1, y, num_rows, num_cols) &&
          (heights[x - 1][y] >= current_height))
        to_visit_atlantic.push({x - 1, y});
      if (isValid(x + 1, y, num_rows, num_cols) &&
          (heights[x + 1][y] >= current_height))
        to_visit_atlantic.push({x + 1, y});
      if (isValid(x, y - 1, num_rows, num_cols) &&
          (heights[x][y - 1] >= current_height))
        to_visit_atlantic.push({x, y - 1});
      if (isValid(x, y + 1, num_rows, num_cols) &&
          (heights[x][y + 1] >= current_height))
        to_visit_atlantic.push({x, y + 1});
    }

    vector<vector<int>> result;
    for (int i = 0; i < num_rows; ++i) {
      for (int j = 0; j < num_cols; ++j) {
        if (visited_pacific[i][j] && visited_atlantic[i][j])
          result.push_back({i, j});
      }
    }
    return result;
  }
};
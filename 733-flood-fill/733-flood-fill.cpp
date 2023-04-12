class Solution {
public:
  bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    // Implement DFS from source. BFS would not work as the colour of the
    // starting pixel would update before checking for neighbours
    int numRows = image.size(), numCols = image[0].size();
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    queue<pair<int, int>> toVisit;
    toVisit.push({sr, sc});
    int source_color = image[sr][sc];

    while (!toVisit.empty()) {
      pair<int, int> current_location = toVisit.front();
      toVisit.pop();

      int current_row = current_location.first,
          current_col = current_location.second;
      int current_color = image[current_row][current_col];

      if (current_color != source_color || visited[current_row][current_col])
        continue; // Skip all pixels that are wrong colour or already visited

      image[current_row][current_col] = color;  // Colour current pixel
      visited[current_row][current_col] = true; // Mark current pixel as visited

      // Queue all valid neighbours
      if (isValid(current_row - 1, current_col, numRows, numCols))
        toVisit.push({current_row - 1, current_col});
      if (isValid(current_row + 1, current_col, numRows, numCols))
        toVisit.push({current_row + 1, current_col});
      if (isValid(current_row, current_col - 1, numRows, numCols))
        toVisit.push({current_row, current_col - 1});
      if (isValid(current_row, current_col + 1, numRows, numCols))
        toVisit.push({current_row, current_col + 1});
    }
    return image;
  }
};
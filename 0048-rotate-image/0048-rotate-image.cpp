class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {  // Transpose the matrix
      for (int j = i; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // Reverse each row
    // Notice that we need to access row by reference
    for (auto& row : matrix) {
      reverse(row.begin(), row.end());
    }
  }
};
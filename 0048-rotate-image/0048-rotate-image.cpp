class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix
        // Reverse each row
        
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (auto &row: matrix) { // Notice that we need to access row by reference
            reverse(row.begin(), row.end());
        }
        
        // for (auto row: matrix) {
        //     for (auto x: row) cout << x << " ";
        //     cout << endl;
        // }
    }
};
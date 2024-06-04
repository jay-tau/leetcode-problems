class Solution {
private:
    int lookup(const vector<vector<int>> &matrix, int index) {
        int m = matrix.size(), n = matrix[0].size();
        
        int row = index / n, col = index % n;
        
        if (!(((0 <= row) && (row < m)) && ((0 <= col) && (col < n)))) {
            cout << "ERROR: lookup(" << index << ")\t"<< "(" << row << "," << col << ")" << endl;
            return -1;
        }
        
        return matrix[row][col];
    }
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int N = m * n;
        
        int l = 0, r = N - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int x = lookup(matrix, mid);
            
            if (x == target)
                return true;
            else if (x > target) // Move left
                r = mid - 1;
            else if (x < target) // Move right
                l = mid + 1;
            else {
                // cout << format("mid: {}, l: {}, r: {}", mid, l, r) << endl;
                return false;
            }
        }
        return false;
    }
};
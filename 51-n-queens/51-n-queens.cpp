class Solution {
private:
    void f(int x, int n, vector<string> &v, vector<vector<string>> &ans, vector<bool> &row_queen, vector<bool> &diag1, vector<bool> &diag2) {
        if (x == n) {
            ans.push_back(v); // n-th queen is only placed if valid
            return;
        }
        if (x > n) { cout << "ERROR: x > n" << endl; return; }
        
        for (int y = 0; y < n; ++y) { // x is fixed
        int current_row = y, current_diag1 = (x+y), current_diag2 = ((n-1) + (x-y));
            if (!row_queen[current_row] && !diag1[current_diag1] && !diag2[current_diag2]) {                
                v[x][y] = 'Q';
                row_queen[current_row] = true;
                diag1[current_diag1] = true;
                diag2[current_diag2] = true;
                
                f(x+1, n, v, ans, row_queen, diag1, diag2);
                
                row_queen[current_row] = false;
                diag1[current_diag1] = false;
                diag2[current_diag2] = false;
                v[x][y] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<bool> row_queen(n, false), diag1_queen(2*n, false), diag2_queen(2*n, false);
        
        f(0, n, v, ans, row_queen, diag1_queen, diag2_queen);
        
        return ans;
    }
};
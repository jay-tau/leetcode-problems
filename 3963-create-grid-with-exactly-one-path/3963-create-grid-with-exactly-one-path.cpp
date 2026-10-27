class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        for (int i = 0; i < m; i++) // Cover top-left to bottom-right
            grid[i][0] = '.';
        for (int i = 0; i < n; i++) // Cover bottom-left to bottom-right
            grid[m - 1][i] = '.';

        return grid;
    }
};
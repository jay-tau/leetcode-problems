class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));


        // Cover top-left to bottom-right
        for (int i = 0; i < m; i++)
            grid[i][0] = '.';
        // Cover bottom-left to bottom-right
        for (int i = 0; i < n; i++)
            grid[m - 1][i] = '.';

        return grid;
    }
};
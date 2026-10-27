class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        cout << "grid:" << endl; for (auto s : grid) cout << s << endl;

        // Cover top-left to bottom-right
        for (int i = 0; i < m; i++) {
            grid[i][0] = '.';
        }
        // Cover bottom-left to bottom-right
        for (int i = 0; i < n; i++)
            grid[m-1][i] = '.';

        cout << "grid:" << endl; for (auto s : grid) cout << s << endl;

        return grid;
    }
};
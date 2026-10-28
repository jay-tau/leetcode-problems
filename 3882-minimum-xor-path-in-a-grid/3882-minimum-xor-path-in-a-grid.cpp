class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int x_size = grid.size(), y_size = grid[0].size();

        vector<vector<vector<bool>>> dp(x_size, vector<vector<bool>>(y_size, vector<bool>(1024, false)));
        vector<vector<bool>> visited(x_size, vector<bool>(y_size, false));
        
        f({0, 0}, dp, visited, grid);

        for (int i = 0; i < 1024; i++) {
            if (dp[0][0][i])
                return i;
        }

        return -1;
     }

    void f(pair<int, int> current_pos, vector<vector<vector<bool>>>& dp,
           vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        int x_size = grid.size(), y_size = grid[0].size();

        auto [x, y] = current_pos;

        if ((x == x_size - 1) && (y == y_size - 1))
            dp[x][y][grid[x][y]] = true;

        visited[x][y] = true;

        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};

        for (int _ = 0; _ < 2; _++) {
            int neighbor_x = x + dx[_], neighbor_y = y + dy[_];

            if (neighbor_x >= x_size) continue;
            if (neighbor_y >= y_size) continue;

            if (!visited[neighbor_x][neighbor_y])
                f({neighbor_x, neighbor_y}, dp, visited, grid);

            for (int neighbor_xor = 0; neighbor_xor < 1024; neighbor_xor++) {
                if (dp[neighbor_x][neighbor_y][neighbor_xor]) {
                    int our_xor = grid[x][y] ^ neighbor_xor;
                    dp[x][y][our_xor] = true;
                }
            }
        }
    }
};
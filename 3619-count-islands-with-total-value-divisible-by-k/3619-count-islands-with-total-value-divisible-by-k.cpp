class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // Find an island and if not visited, then do a dfs. Count the sum as it goes
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];

                if (x == 0) {
                    visited[i][j] = true;
                    continue;
                }

                long long island_sum = 0;
                
                dfs({i, j}, island_sum, grid, visited);

                if (island_sum && island_sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }

    static void dfs(const pair<int, int> &pos, long long &running_sum, const vector<vector<int>> &grid, vector<vector<bool>> & visited) {
        auto [x, y] = pos;
        int x_size = grid.size(), y_size = grid[0].size();

        if (visited[x][y] || grid[x][y] == 0) return;
        visited[x][y] = true;

        vector<pair<int, int>> neighbors = findNeighbors(pos, grid);

        for (pair<int, int> neighbor: neighbors) {
            auto [neighbor_x, neighbor_y] = neighbor;

            if (!visited[neighbor_x][neighbor_y])
                dfs(neighbor, running_sum, grid, visited);
        }

        running_sum += grid[x][y];
    }

    static vector<pair<int, int>> findNeighbors(const pair<int, int> &p, const vector<vector<int>> &grid) {
        int x_size = grid.size(), y_size = grid[0].size();
        
        auto [x, y] = p;

        vector<pair<int, int>> neighbors;
        neighbors.reserve(4);

        if (0 <= x - 1)
            neighbors.emplace_back(x - 1, y);
        if (x + 1 < x_size)
            neighbors.emplace_back(x + 1, y);
        if (0 <= y - 1)
            neighbors.emplace_back(x, y - 1);
        if (y + 1 < y_size)
            neighbors.emplace_back(x, y + 1);

        return neighbors;
    }
};
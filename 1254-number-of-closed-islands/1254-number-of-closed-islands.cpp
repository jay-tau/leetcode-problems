#define F first
#define S second


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int x_size = grid.size(), y_size = grid[0].size();
        cout << "x_size: " << x_size << ", y_size: " << y_size << endl;

        // Find all edges
        vector<pair<int, int>> boundaries;
        for (int i = 0; i < y_size; i++) {
            if (grid[0][i] == 0) boundaries.emplace_back(0, i);
            if (grid[x_size-1][i] == 0) boundaries.emplace_back(x_size-1, i);
        }
        for (int i = 0; i < x_size; i++) {
            if (grid[i][0] == 0) boundaries.emplace_back(i, 0);
            if (grid[i][y_size-1] == 0) boundaries.emplace_back(i, y_size-1);
        }
        // cout << "boundaries: "; for (auto p: boundaries) cout << "(" << p.F << "," << p.S << ")" << " "; cout << endl;

        // Start a graph traversal from every edge
        queue<pair<int, int>> q;
        vector<vector<bool>> visited (x_size, vector<bool>(y_size, false));
        for (const auto &pos: boundaries) // Not making a copy of pos
            q.push(pos);
        cout << "visited:" << endl; for (auto v: visited) { for (auto x: v) cout << x << " "; cout << endl; } cout << endl;

        while (!q.empty()) {
            auto [x, y] = q.front(); // Make a copy of the integers
            q.pop();

            if (visited[x][y]) continue;
            visited[x][y] = true;

            vector<pair<int, int>> neighbors;
            neighbors.reserve(4);
            populateNeighbors(x, y, x_size, y_size, neighbors);

            cout << "neighbours of (" << x << "," << y << "): "; for (auto p: neighbors) cout << "(" << p.F << "," << p.S << ")"; cout << endl;

            for (const auto &neighbor: neighbors) {
                if (grid[neighbor.F][neighbor.S] == 0)
                    q.push(neighbor);
            }
        }

        cout << "visited:" << endl; for (auto v: visited) { for (auto x: v) cout << x << " "; cout << endl; } cout << endl;

        vector<vector<int>> remaining_grid(x_size, vector<int>(y_size, 0));
        for (int i = 0; i < x_size; i++) {
            for (int j = 0; j < y_size; j++) {
                int x = grid[i][j];
                if (x == 0 && !visited[i][j])
                    remaining_grid[i][j] = 1;
            }
        }
        cout << "remaining_grid: " << endl; for (auto v: remaining_grid) { for (auto x: v) cout << x << " "; cout << endl; } cout << endl;

        return countIslands(remaining_grid);
    }

    static void populateNeighbors(int x, int y, int x_size, int y_size, vector<pair<int, int>> &neighbors) {
        if (0 <= x - 1) neighbors.emplace_back(x-1, y);
        if (x + 1 < x_size) neighbors.emplace_back(x+1, y);
        if (0 <= y - 1) neighbors.emplace_back(x, y-1);
        if (y + 1 < y_size) neighbors.emplace_back(x, y+1);
    }

    static int countIslands(vector<vector<int>> &grid) {
        int num_islands = 0;
        int x_size = grid.size(), y_size = grid[0].size();

        for (int i = 0; i < x_size; i++) {
            for (int j = 0; j < y_size; j++) {
                int x = grid[i][j];
                if (x != 0) {
                    num_islands++;
                    dfs({i, j}, grid);
                }
            }
        }

        return num_islands;

        return -1;
    }

    static void dfs(const pair<int, int> &start, vector<vector<int>> &grid) {
        int x_size = grid.size(), y_size = grid[0].size();

        auto [x, y] = start;

        if (grid[x][y] == 0) return;
        grid[x][y] = 0;

        vector<pair<int, int>> neighbors;
        neighbors.reserve(4);
        populateNeighbors(x, y, x_size, y_size, neighbors);

        cout << "neighbours of (" << x << "," << y << "): "; for (auto p: neighbors) cout << "(" << p.F << "," << p.S << ")"; cout << endl;

        for (const auto &neighbor: neighbors) dfs(neighbor, grid);
    }
};
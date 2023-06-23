class Solution {
private:
    bool isValid(int x, int y, int n, int m) {
        return (((0 <= x) && (x < n)) && ((0 <= y) && (y < m)));
    }
    vector<pair<int, int>> adj(pair<int, int> current_node, int n, int m) {
        vector<pair<int, int>> adj_list;
        int x = current_node.first, y = current_node.second;
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int i = 0;  i < 4; ++i) {
            int new_x = x+dx[i], new_y = y+dy[i];
            if (isValid(new_x, new_y, n, m))
                adj_list.push_back({new_x, new_y});
        }
        return adj_list;
    }
    void dfs(pair<int, int> current_node, vector<vector<bool>> &visited, vector<vector<int>> &grid, int n, int m) {
        int x = current_node.first, y = current_node.second;
        if (visited[x][y])
            return;
        if (grid[x][y] == 0) { // Unvisited sea
            visited[x][y] = true;
            return;
        }
        
        visited[x][y] = true;
        
        for (pair<int, int> adj_node: adj(current_node, n, m)) {
            int adj_x = adj_node.first, adj_y = adj_node.second;
            if (!visited[adj_x][adj_y])
                dfs(adj_node, visited, grid, n, m);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Find the number of cells which are 1 and are not connected to the edge.
        int n = grid.size(), m = grid[0].size();
        
        set<pair<int, int>> sources;
        
        // Find all edge 1's
        for (int i = 0; i < n; ++i) { // {i, 0/m-1}
            if (grid[i][0] == 1)
                sources.insert({i, 0});
            if (grid[i][m-1])
                sources.insert({i, m-1});
        }
        for (int j = 0; j < m; ++j) {
            if (grid[0][j] == 1)
                sources.insert({0, j});
            if (grid[n-1][j] == 1)
                sources.insert({n-1, j});
        }
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (auto source: sources) {
            dfs(source, visited, grid, n, m);
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((grid[i][j] == 1) && !visited[i][j])
                    ++count;
            }
        }
        
        return count;
    }
};
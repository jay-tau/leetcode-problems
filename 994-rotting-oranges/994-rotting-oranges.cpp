class Solution {
private:
    bool isValid(int x, int y, int n, int m) {
        return (0 <= x) && (x < n) && (0 <= y) && (y < m);
    }
    vector<vector<int>> adj(vector<int> v, int n, int m) {
        vector<vector<int>> adj_list;
        
        int x = v[0], y = v[1], current_time = v[2];
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i], new_y = y + dy[i];
            if (isValid(new_x, new_y, n, m))
                adj_list.push_back({new_x, new_y, (current_time+1)});
        }
        return adj_list;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Peform BFS. Store time in queue
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<vector<int>> q; // {x, y, time}
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    dist[i][j] = 0;
                    q.push({i, j, 0});
                } else if (grid[i][j] == 0)
                    dist[i][j] = 0;
            }
        }
        
        while (!q.empty()) {
            vector<int> current_node = q.front();
            q.pop();
            int x = current_node[0], y = current_node[1], t = current_node[2];
            
            if (visited[x][y] || (grid[x][y] == 0))
                continue;
            
            visited[x][y] = true;
            if (grid[x][y] == 1)
                dist[x][y] = t;
            
            // Add adjacent nodes
            for (auto adj_node: adj(current_node, n, m))
                if (!visited[adj_node[0]][adj_node[1]] && grid[x][y] != 0)
                    q.push(adj_node);
        }
        
        int max_time = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_time = max(max_time, dist[i][j]);
            }
        }
        
        return (max_time == INT_MAX) ? -1 : max_time;
    }
};
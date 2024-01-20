class Solution {
private:
    bool isValid(int x, int y, int n, int m) {
        return (0 <= x) && (x < n) && (0 <= y) && (y < m);
    }
    vector<pair<int, int>> adj(pair<int, int> current_node, int n, int m) {
        vector<pair<int, int>> adj_list;
        int x = current_node.first, y = current_node.second;
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int new_x = x+dx[i], new_y = y+dy[i];
            if (isValid(new_x, new_y, n, m))
                adj_list.push_back({new_x, new_y});
        }
        return adj_list;
    }
    void dfs(pair<int, int> &current_node, vector<vector<bool>> &visited, vector<vector<bool>> &crossed, vector<vector<char>> &grid, int &n, int &m) {
        int x = current_node.first, y = current_node.second;
        visited[x][y] = true;
        if (grid[x][y] == 'X')
            return;
        if (grid[x][y] == 'O') {
            crossed[x][y] = false; // Only borders and their adjacents are called
        }
        for (auto adj_node: adj(current_node, n, m)) {
            int adj_x = adj_node.first, adj_y = adj_node.second;
            if (visited[adj_x][adj_y])
                continue;
            if (grid[adj_x][adj_y] == 'X')
                continue;
            if (crossed[adj_x][adj_y] == false)
                continue;
            dfs(adj_node, visited, crossed, grid, n, m);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // Perform a dfs. If any lower node is not possible, then the current node won't be
        // Start from every invalid O (boundary) and perform dfs, to mark all unflippable O's
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> crossed(n, vector<bool>(m, true));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        set<pair<int, int>> sources;
        // Add border O's to sources
        for (int j = 0; j < m; ++j) { // (0/n-1, j)
            if (board[0][j] == 'O')
                sources.insert({0, j});
            if (board[n-1][j] == 'O')
                sources.insert({n-1, j});
        }
        for (int i = 0; i < n; ++i) { // {i, 0/m-1}
            if (board[i][0] == 'O')
                sources.insert({i, 0});
            if (board[i][m-1] == 'O')
                sources.insert({i, m-1});
        }
        
        for (auto source: sources) {
            dfs(source, visited, crossed, board, n, m);
        }
        
        // for (auto v: crossed) {for (auto x: v) {cout << x << " ";}cout << endl;}
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0;  j < m; ++j) {
                if (crossed[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
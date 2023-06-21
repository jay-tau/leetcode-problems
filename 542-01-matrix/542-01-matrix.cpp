class Solution {
 private:
  bool isValid(int x, int y, int n, int m) {
    return (0 <= x) && (x < n) && (0 <= y) && (y < m);
  }
  vector<pair<int, int>> adj(pair<int, int> p, int n, int m) {
    vector<pair<int, int>> adj_list;
    int x = p.first, y = p.second;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
      int new_x = x + dx[i], new_y = y + dy[i];
      if (isValid(new_x, new_y, n, m)) adj_list.push_back({new_x, new_y});
    }

    return adj_list;
  }
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    // Perform multisource BFS
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));  // Stores distancee
    // vector<vector<pair<int, int>>> parent(
    //     n, vector<pair<int, int>>(m, {-1, -1}));  // Default parent = -1
    queue<pair<pair<int, int>, int>> q;           // {{x, y}, parent}

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 0) {                 // Source
          // parent[i][j] = {INT_MIN, INT_MIN};  // Source parent = -1
          dist[i][j] = 0;                     // Distance is 0
          q.push({{i, j}, 0});                // Push to queue
        }
      }
    }

    while (!q.empty()) {
      pair<pair<int, int>, int> p = q.front();
      q.pop();
      pair<int, int> current_node = p.first;
      int x = p.first.first, y = p.first.second, d = p.second;

      for (pair<int, int> adj_pair : adj(p.first, n, m)) {
        int adj_x = adj_pair.first, adj_y = adj_pair.second, adj_dist = d + 1;
        // pair<int, int> source_parent = {INT_MIN, INT_MIN};
        if (mat[adj_x][adj_y] == 0)  // Skip other sources
          continue;
        if (adj_dist < dist[adj_x][adj_y]) {
          dist[adj_x][adj_y] = adj_dist;        // Update distance
          // parent[adj_x][adj_y] = current_node;  // Update parent
          q.push({adj_pair, adj_dist});
        }
      }
    }

    return dist;
  }
};
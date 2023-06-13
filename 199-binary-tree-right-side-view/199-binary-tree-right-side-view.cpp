/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
 public:
  /**
   * @param root: the root of the given tree
   * @return: the values of the nodes you can see ordered from top to bottom
   */
  vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) return {};

    map<int, int> m;                // { level, node->val }
    queue<pair<TreeNode*, int>> q;  // { node, level }

    q.push({root, 0});

    while (!q.empty()) {
      pair<TreeNode*, int> p = q.front();
      q.pop();
      TreeNode* current_node = p.first;
      int current_level = p.second;

      if (current_node == nullptr) continue;

      m[current_level] = current_node->val;

      q.push({current_node->left,
              current_level + 1});  // In case node->right is nullptr
      q.push({current_node->right, current_level + 1});
    }

    vector<int> right_view;
    for (pair<int, int> p : m) {
      int level = p.first, node = p.second;
      right_view.push_back(node);
    }

    return right_view;
  }
};
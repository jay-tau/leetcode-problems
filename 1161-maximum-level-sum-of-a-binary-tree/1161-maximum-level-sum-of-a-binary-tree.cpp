/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    if (root == nullptr) return INT_MIN;

    int level = 1, max_sum = INT_MIN, max_level = -1;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int q_size = q.size();
      int level_sum = 0;

      while (q_size--) {
        TreeNode* current_node = q.front();
        q.pop();

        if (current_node == nullptr) continue;

        level_sum += (current_node->val);

        // Check for null. Adding a null level, sets max_sum to 0
        if (current_node->left) q.push(current_node->left);
        if (current_node->right) q.push(current_node->right);
      }

      if (level_sum > max_sum) {
        max_sum = level_sum;
        max_level = level;
      }
      level++;
    }

    return max_level;
  }
};
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
 private:
  int max_diameter = 0;
  int height(TreeNode* node) {
    if (node == nullptr) return 0;

    int left_height = height(node->left), right_height = height(node->right);

    max_diameter = max(max_diameter,
                       (left_height + right_height));  // Used to update global
    // max diameter value.
    // Only line that differs
    // from a height function

    return 1 + max(left_height, right_height);  // Returns height
  }

 public:
  int diameterOfBinaryTree(TreeNode* root) {
    height(root);
    return max_diameter;
  }
};
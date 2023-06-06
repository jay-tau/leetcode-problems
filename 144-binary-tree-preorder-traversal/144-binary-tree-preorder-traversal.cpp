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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traversal;

    if (root == nullptr) return {};

    traversal.push_back(root->val);

    for (auto x : preorderTraversal(root->left)) traversal.push_back(x);
    for (auto x : preorderTraversal(root->right)) traversal.push_back(x);

    return traversal;
  }
};
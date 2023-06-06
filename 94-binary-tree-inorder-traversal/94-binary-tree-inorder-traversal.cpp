/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        
        if (root == nullptr)
            return {};
        
        for (auto x: inorderTraversal(root->left))
            traversal.push_back(x);
        traversal.push_back(root->val);
        for (auto x: inorderTraversal(root->right))
            traversal.push_back(x);
        
        return traversal;
    }
};
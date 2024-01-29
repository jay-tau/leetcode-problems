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
private:
    vector<int> v;
    void f(TreeNode* current) {
        if (!current) return;
        
        v.push_back(current->val);
        f(current->left);
        f(current->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        f(root);
        return v;
    }
};
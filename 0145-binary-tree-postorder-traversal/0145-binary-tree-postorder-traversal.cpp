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
        
        f(current->left);
        f(current->right);
        v.push_back(current->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return v;
    }
};
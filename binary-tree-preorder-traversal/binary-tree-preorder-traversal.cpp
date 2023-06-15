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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<int> traversal;
        stack<TreeNode*> s;
        
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* current_node = s.top();
            s.pop();
            
            if (current_node == nullptr)
                continue;
            
            traversal.push_back(current_node->val);
            s.push(current_node->right);
            s.push(current_node->left);
        }
        return traversal;
    }
};
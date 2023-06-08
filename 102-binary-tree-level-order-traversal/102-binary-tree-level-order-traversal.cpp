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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> level_order_traversal;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> level;
            while (level_size--) {
                TreeNode* current_node = q.front();
                q.pop();
                
                if (current_node == nullptr)
                    continue;
                
                level.push_back(current_node->val);
                q.push(current_node->left);
                q.push(current_node->right);
            }
            if (level.size() > 0)
                level_order_traversal.push_back(level);
        }
        return level_order_traversal;
    }
};
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
        vector<vector<int>> level_order_traversal;
        queue<TreeNode*> q;
        
        if (root) q.push(root);
        
        while (!q.empty()) {
            int current_level_size = q.size();
            vector<int> current_level;
            
            for (int i = 0; i < current_level_size; i++) {
                TreeNode* current_node = q.front();
                q.pop();
                
                current_level.push_back(current_node->val);
                if (current_node->left)
                    q.push(current_node->left);
                if (current_node->right)
                    q.push(current_node->right);
            }
            
            level_order_traversal.push_back(current_level);
        }
        
        // level_order_traversal.pop_back(); // To remove last level of all nullptrs
        
        return level_order_traversal;
    }
};
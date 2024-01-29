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
    vector<int> rightSideView(TreeNode* root) {
        // Perform BFS, and replace the last element
        vector<int> right_side_view;
        int level = 0;
        
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            
            right_side_view.push_back(INT_MAX);
            
            while (level_size--) {
                TreeNode* current_node = q.front();
                q.pop();
                
                right_side_view[level] = current_node->val;
                
                if (current_node->left) q.push(current_node->left);
                if (current_node->right) q.push(current_node->right);
            }
            level++;
        }
        
        return right_side_view;
    }
};
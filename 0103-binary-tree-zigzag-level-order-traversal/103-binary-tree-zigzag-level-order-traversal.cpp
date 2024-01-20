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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> traversal;
        deque<TreeNode*> q;
        bool left_to_right = true;
        
        q.push_back(root);
        
        while (!q.empty()) {
            vector<int> current_level;
            int level_size = q.size();
            
            while (level_size--) {
                TreeNode* current_node;
                
                if (left_to_right) {
                    current_node = q.front();
                    q.pop_front();
                } else {
                    current_node = q.back();
                    q.pop_back();
                }

                if (current_node == nullptr)
                    continue;
                current_level.push_back(current_node->val);

                if (left_to_right) {
                    q.push_back(current_node->left);
                    q.push_back(current_node->right);
                } else {
                    q.push_front(current_node->right);
                    q.push_front(current_node->left);
                }
            }
            if (current_level.size() > 0)
                traversal.push_back(current_level);
            left_to_right = !left_to_right;
        }
        
        return traversal;
    }
};
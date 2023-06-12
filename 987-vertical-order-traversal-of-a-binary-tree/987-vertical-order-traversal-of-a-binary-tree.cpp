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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> vertical_traversal;
        map<int, map<int, vector<int>>> m; // {offset, level, nodes}
        queue<pair<TreeNode*, pair<int, int>>> q; // { node, offset, level }
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> p = q.front();
            q.pop();
            TreeNode* current_node = p.first;
            int current_offset = p.second.first, current_level = p.second.second;
            
            if (current_node == nullptr)
                continue;
            
            m[current_offset][current_level].push_back(current_node->val); // Insert into its position
            
            // Add children into queue
            if (current_node->left != nullptr)
                q.push({current_node->left, {current_offset-1, current_level+1}});
            if (current_node->right != nullptr)
                q.push({current_node->right, {current_offset+1, current_level+1}});
        } // End while
        
        for (pair<int, map<int, vector<int>>> outer_map: m) {
            
            map<int, vector<int>> inner_map = outer_map.second;
            
            vector<int> vertical_traversal_offset_temp; // All offsets need to be in a single vector
            
            for (pair<int, vector<int>> p2: inner_map) {
                vector<int> level_in_offset = p2.second;
                sort(level_in_offset.begin(), level_in_offset.end()); // Sorting only occurs within a level
                for (int x: level_in_offset)
                    vertical_traversal_offset_temp.push_back(x);
            }
            vertical_traversal.push_back(vertical_traversal_offset_temp);
        }
        
        return vertical_traversal;
    }
};
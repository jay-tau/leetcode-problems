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
    int max_sum = INT_MIN;
    int search(TreeNode* node) {
        if (node == nullptr)
            return 0;
        
        int left_sum = search(node->left), right_sum = search(node->right);
        int current_sum = (node->val) + max(0, left_sum) + max(0, right_sum);
        
        max_sum = max(max_sum, current_sum);
        
        return (node->val) + max(0, max(left_sum, right_sum));
    }
public:
    int maxPathSum(TreeNode* root) {
        search(root);
        return max_sum;
    }
};
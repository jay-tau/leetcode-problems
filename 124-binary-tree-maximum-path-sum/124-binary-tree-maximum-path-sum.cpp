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
        
        int left_sum = max(0, search(node->left)), right_sum = max(0, search(node->right));
        
        // node is in the middle in current sum
        int current_sum = (node->val) + left_sum + right_sum; // Current sum will include subtree sums, only if they are positive
        max_sum = max(max_sum, current_sum);
        
        // node is not in the middle. So that node can connect with its parent
        return (node->val) + max(left_sum, right_sum); // Only 1 subtree can be included. If both are negative, none are included
    }
public:
    int maxPathSum(TreeNode* root) {
        search(root);
        return max_sum;
    }
};
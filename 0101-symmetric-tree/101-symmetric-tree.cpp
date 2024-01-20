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
    void mirror(TreeNode* node) {
        if (node == nullptr)
            return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
    bool isEqual(TreeNode* lnode, TreeNode* rnode) {
        if ((lnode == nullptr)^(rnode == nullptr)) // Only 1 is nullptr
            return false;
        if ((lnode == nullptr) && (rnode == nullptr)) // Both are nullptr
            return true;
        
        return (lnode->val == rnode->val) && isEqual(lnode->left, rnode->left) && isEqual(lnode->right, rnode->right);
     }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        // Mirror left and check if it is same. // O(n) + O(n)
        mirror(root->right);
        return isEqual(root->left, root->right);
    }
};
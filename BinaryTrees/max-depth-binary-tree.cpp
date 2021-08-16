/**
  https://leetcode.com/problems/maximum-depth-of-binary-tree/
  
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
    int maxDepth(TreeNode* root) {
        int l = INT_MIN, r = INT_MIN;
        if(root == NULL) {
            return 0;
        }
        
        if(root->left == NULL and root->right == NULL) {
            return 1;
        }
        
        if(root->left) {
            l = maxDepth(root->left);
        }
        
        if(root->right) {
            r = maxDepth(root->right);
        }
        
        return max(l,r) + 1;
    }
};
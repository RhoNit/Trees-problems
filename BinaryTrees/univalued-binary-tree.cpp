/**
  https://leetcode.com/problems/univalued-binary-tree/
  
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
    int flag = 1;
    bool isUnivalTree(TreeNode* root) {
        return helperFunction(root, root->val);
    }
    
    int helperFunction(TreeNode *root, int data) {
        if(root == NULL) { 
            return false;
        }
        
        if(root->val != data) {
            flag = 0;
            return false;
        }
        
        helperFunction(root->left, root->val);
        helperFunction(root->right, root->val);
        
        return flag;
    }
};
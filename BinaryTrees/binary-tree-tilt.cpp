/**
  https://leetcode.com/problems/binary-tree-tilt/

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
    //to store the tilts for every node
    int temp = 0;
    
    int helperFunction(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int l = helperFunction(root->left);
        int r = helperFunction(root->right);
        
        //we're storing |l-r| for every node in 'temp'.
        //ultimately sum of 'temp' for every node will be returned.
        temp += abs(l-r);
        
        //side by side, we're updating the root value of every node as sum of its left subtree and that of its right subtree plus its own value.  
        root->val = root->val + l + r;
        
        return root->val;
    }
    
    int findTilt(TreeNode* root) {
        helperFunction(root);
        return temp;
    }
};
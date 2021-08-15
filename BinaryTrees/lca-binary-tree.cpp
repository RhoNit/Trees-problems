/**
  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root == p or root == q) {
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        //case 1: 'p' would be in the left subtree and 'q' would be in the right subtree or vice versa. In this case, 'root' would be the LCA as both nodes are in different subtrees.
        //case 2: both 'p' and 'q' are in the same subtree. In this case, 'root' won't be the LCA ('root' is a common ancestor but not the lowest one). 
        if(left != NULL and right != NULL) {
            return root;
        }
        
        //case 3: both 'p' and 'q' are in left subtree. And if 'p' is the first traversed one, 'p' would be the LCA. In this case, p->right == NULL.
        if(left != NULL) {
            return left;
        }

        //case 3: both 'p' and 'q' are in right subtree. And if 'p' is the first traversed one, 'p' would be the LCA. In this case, p->left == NULL.
        else {
            return right;
        }
    }
};
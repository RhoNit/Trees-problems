/**
 
 https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode* root) {
        bool isComplete = false;
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            TreeNode *node = Q.front();
            Q.pop();
            
            /*Completeness: once we've found a NULL node at last level, there shouldn't be any value after that node.
            That's why we're marking 'isComplete' as 'true'. 
            And the value of 'isComplete' shouldn't be changed in case of the tree to be a Complete Binary Tree.*/
            if(node == NULL) {
                isComplete = true;
            }
            
            else {
                /*Incompleteness: if we encounter a node value and 'isComplete' is already 'true' i.e. 
                we already have found a NULL node and we're again getting a node value after that, 
                then the tree won't be a Complete Binary Tree. In that case, we'll simply return 'isComplete' as 'false'*/  
                if(isComplete == true) { return false; }
                
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        return true;
    }
};
/**

 https://leetcode.com/problems/symmetric-tree/
  ____________________________
 |                            |
 | Time Complexity: O(n)      |
 | Space Complexity: O(w1+w2) |
 |____________________________|

 basically 2 queues are used here..that's why widths of both binary trees are mentioned.
 w --> max. width of the binary tree i.e. max. no. of elements in any level of the binary tree.


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
    bool helperFunction(TreeNode *l, TreeNode *r) {
        queue<TreeNode *> Q1;
        queue<TreeNode *> Q2;
        
        Q1.push(l);
        Q2.push(r);
        
        while(!Q1.empty() and !Q2.empty()) {
            l = Q1.front();
            Q1.pop();
            
            r = Q2.front();
            Q2.pop();
            
            if(l == NULL and r == NULL) { continue; }
            if(l == NULL and r != NULL) { return false; }
            if(l != NULL and r == NULL) { return false; }
            if(l->val != r->val) { return false; }
            
            if(l->left) { Q1.push(l->left); }
            else { Q1.push(NULL); }
            
            if(l->right) { Q1.push(l->right); }
            else { Q1.push(NULL); }
            
            
            if(r->right) { Q2.push(r->right); }
            else { Q2.push(NULL); }
            
            if(r->left) { Q2.push(r->left); }
            else { Q2.push(NULL); }
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) { return false; }
        
        return helperFunction(root->left, root->right);
    }
};

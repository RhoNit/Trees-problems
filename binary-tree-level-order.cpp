/**
 https://leetcode.com/problems/binary-tree-level-order-traversal/
 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        
        if(root == NULL) { return vec; }
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            int n = Q.size();
            vector<int> v;
            
            for(int i = 0; i < n; i++) {
                TreeNode *front = Q.front();
                Q.pop();
                
                if(front->left) { Q.push(front->left); }
                if(front->right) { Q.push(front->right); }
                
                v.push_back(front->val);
            }
            vec.push_back(v);
        }
        return vec;
    }
};
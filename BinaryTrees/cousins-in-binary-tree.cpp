/**
 https://leetcode.com/problems/cousins-in-binary-tree/

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
    void findDepth(TreeNode *root, int depth, int parent, int &x, int &y, pair<int,int> &p1, pair<int,int> &p2) {
        //if node is NULL
        if(root == NULL) { return; }
        
        if(root->val == x) {
            p1.first = parent;
            p1.second = depth;
        }
        
        if(root->val == y) {
            p2.first = parent;
            p2.second = depth;
        }
        
        findDepth(root->left, depth+1, root->val, x, y, p1, p2);
        findDepth(root->right, depth+1, root->val, x, y, p1, p2);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> p;
        pair<int, int> q;
        
        findDepth(root, 0, -1, x, y, p, q);
        
        if(p.first != q.first and p.second == q.second) { return true; }
        return false;
    }
};
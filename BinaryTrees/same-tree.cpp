/**
  https://leetcode.com/problems/same-tree/
   ___________________________
  |                           |
  |  Time Complexity: O(n)    |
  |  Space Complexity: O(w)   |
  |___________________________|


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode *, TreeNode *>> Q;
        Q.push({p, q});
        
        while(!Q.empty()) {
            TreeNode *root1 = Q.front().first;
            TreeNode *root2 = Q.front().second;
            
            Q.pop();
            
            if(root1 == NULL and root2 == NULL) {
                continue;
            }
            
            if(root1 == NULL or root2 == NULL or (root1->val != root2->val)) {
                return false;
            }
            
            else {
                Q.push({root1->left, root2->left});
                Q.push({root1->right, root2->right});
            }
        }
        return true;
    }
};
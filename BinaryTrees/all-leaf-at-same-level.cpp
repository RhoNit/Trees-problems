/** 
   https://practice.geeksforgeeks.org/problems/leaf-at-same-level/
    _________________________
   |                         |                 |
   | Time Complexity: O(n)   |
   | Space Complexity: O(w)  |
   |_________________________|

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
    bool check(TreeNode *root) {
        queue<pair<TreeNode *, int>> Q;
        Q.push({root,0});
        
        map<int, int> mp;
        
        while(!Q.empty()) {
            pair<TreeNode *, int> p = Q.front();
            Q.pop();
            
            TreeNode *temp = p.first;
            int line = p.second;
            
            if(temp->left == NULL and temp->right == NULL) {
                mp[line] = temp->val;
            }
            
            if(temp->left) { Q.push({temp->left, line+1}); }
            if(temp->right) { Q.push({temp->right, line+1}); }
        }
        if(mp.size() > 1) { return false; }
        else { return true; }
    }
};
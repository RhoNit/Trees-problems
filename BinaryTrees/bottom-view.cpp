/**

  https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/

   ___________________________
  |                           |
  | Time Complexity: O(NlogN) |
  | Space Complexity: O(N)    |
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
    vector<int> bottomView(TreeNode *root) {
        vector<int> vec;
        if(root == NULL) { return vec; }
        
        queue<pair<TreeNode *, int>> Q;
        Q.push({root,0});
        
        map<int, int> mp;
        
        while(!Q.empty()) {
            pair<TreeNode *, int> p = Q.front();
            Q.pop();
            
            TreeNode *node = p.first;
            int lineNum = p.second;
            
            mp[lineNum] = root->data;
            
            if(node->left) { Q.push({node->left, lineNum-1}); }
            if(node->right) { Q.push({node->right, lineNum+1}); }
        }

        for(auto it : mp) {
            vec.push_back(it.second);
        }
        
        return vec;
    }
};
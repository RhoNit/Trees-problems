/**

  https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/

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
    vector<int> topView(TreeNode *root) {
        vector<int> vec;
        
        queue<pair<TreeNode *,int>> Q;
        Q.push({root,0});
        
        map<int, int> mp;
        
        while(!Q.empty()) {
            pair<TreeNode *,int> p = Q.front();
            Q.pop();
            
            TreeNode *node = p.first;
            int line = p.second;
            
            if(mp.find(line) == mp.end()) {
                mp[line] = root->data;
            }
            
            if(node->left) {
                Q.push({node->left, line-1});
            }
            
            if(node->right) {
                Q.push({node->right, line+1});
            }
        }
        for(auto it : mp) {
            vec.push_back(it.second);
        }
        
        return vec;
    }
};
/**

  https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/

   ___________________________
  |                           |
  | Time Complexity: O(n)     |
  | Space Complexity: O(n)    |
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
    vector<int> leftView(TreeNode* root) {
        vector<int> vec;
        if(root == NULL) { return vec; }
        
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            int n = Q.size();
            vec.push_back(Q.front()->val);
            while(n--) {
                TreeNode *temp = Q.front();
                Q.pop();
                
                if(temp->left) { Q.push(temp->left); }
                if(temp->right) { Q.push(temp->right); }
            }
        }
        return vec;
    }
};
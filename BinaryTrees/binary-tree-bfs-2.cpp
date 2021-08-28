/**
 
 https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> reverseVec(vector<vector<int>> result, int i, int j) {
        while(i < j) {
            swap(result[i++], result[j--]);
        }
        return result;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        
        if(root == NULL) {
            return vec;
        }
        
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            int n = Q.size();
            vector<int> v;
            while(n--) {
                TreeNode *front = Q.front();
                Q.pop();
                v.push_back(front->val);
                
                if(front->left) {
                    Q.push(front->left);
                }
                if(front->right) {
                    Q.push(front->right);
                }
            }
            vec.push_back(v);
        }
        return reverseVec(vec, 0, vec.size()-1);
    }
};
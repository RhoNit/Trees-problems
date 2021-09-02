/**

  https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/

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
    vector<int> diagonalTraversal(TreeNode *root) {
    	vector<int> vec;
   		if(root == NULL) { return vec; }
   
   		queue<TreeNode *> Q;
   		Q.push(root);
   
   		while(!Q.empty()) {
       		TreeNode *temp = Q.front();
       		Q.pop();

       		while(temp != NULL) {
           		if(temp->left) {
           			Q.push(temp->left);
           		}
           		vec.push_back(temp->val);
           		temp = temp->right;
       		}
   		}
   		return vec;
	}
};


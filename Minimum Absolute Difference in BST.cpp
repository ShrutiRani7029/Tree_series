/**
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

   void util(TreeNode* root,int &prev , int &mn){
       if(root==NULL)return;

       util(root->left, prev,mn);
       mn=min(mn,abs(prev-root->val));

       prev=root->val;
       util(root->right,prev,mn);
   }
    


    int getMinimumDifference(TreeNode* root) {
        int min=INT_MAX;
        int prev=INT_MAX/2;///NOT OVERFLOWING
        util(root,prev,min);
        return min;
    }
};

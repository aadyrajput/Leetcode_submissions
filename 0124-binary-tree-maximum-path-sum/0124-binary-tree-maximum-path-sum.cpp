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
private:
int fun(TreeNode* root,int &sum){
    if(root==NULL){
        return 0;
    }
   int lh=max(0,fun(root->left,sum));
   int rh=max(0,fun(root->right,sum));

   sum=max(sum,lh+rh+root->val);
   return root->val+max(lh,rh);
}


public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        fun(root,sum);
        return sum;
    }
};
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


int fun(TreeNode* x,int &ans){
    if(x==NULL)return 0;
    int lsum=max(0,fun(x->left,ans));
    int rsum=max(0,fun(x->right,ans));
    ans=max(ans,lsum+rsum+x->val);
    return x->val+max(lsum,rsum);
}
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=INT_MIN;
        fun(root,ans);
        return ans;
    }
};
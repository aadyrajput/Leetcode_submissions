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
    if(root==NULL)return 0;
    int lh=fun(root->left,sum);
    int rh=fun(root->right,sum);
    lh=max(0,lh);
    rh=max(0,rh);
    sum=max(sum,root->val+lh+rh);
    return root->val+max(lh,rh);
}
public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        if(root==NULL)return 0;
        fun(root,sum);
        return sum;
    }
};
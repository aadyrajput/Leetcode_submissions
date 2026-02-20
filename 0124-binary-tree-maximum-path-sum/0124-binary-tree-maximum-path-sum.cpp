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
    int ans;
    int fun(TreeNode* root){
        if(root==NULL) return 0;
        int lf=fun(root->left);
        int rf=fun(root->right);

        int neeche_milgaya=root->val+lf+rf;
        int koi_ekacha=max(lf,rf)+root->val;
        int keval_rootacha=root->val;
        ans=max({ans,neeche_milgaya,koi_ekacha,keval_rootacha});
        return max(koi_ekacha,keval_rootacha);
    }

    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        fun(root);
        return ans;
    }
};
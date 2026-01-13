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
void fun(TreeNode* x,int mina,int maxa,int &ans){
    if(x==NULL)return;
    mina=min(mina,x->val);
    maxa=max(maxa,x->val);
    if(x->left==NULL && x->right==NULL){
        ans=max(ans,abs(mina-maxa));
    }
    else{
        fun(x->left,mina,maxa,ans);
        fun(x->right,mina,maxa,ans);
    }
}
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        fun(root,INT_MAX,INT_MIN,ans);
        return ans;
    }
};
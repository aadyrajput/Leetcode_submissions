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
int fun(TreeNode* x,bool &flag){
    if(x==NULL)return 0;
    int lh=fun(x->left,flag);
    int rh=fun(x->right,flag);
    if(abs(rh-lh)>1)flag&=false;
    return 1+max(lh,rh);
}
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool flag=true;
        fun(root,flag);
        return flag;
    }
};
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
int tot(TreeNode* root){
    if(root==NULL)return 0;
    return 1+tot(root->left)+tot(root->right);
}
int fun(TreeNode* root,int i,int total){
    if(root==NULL)return true;
    if(i>total)return false;
    return fun(root->left,2*i,total) && fun(root->right,2*i +1, total);
}
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)return true;
        int total=tot(root);
        return fun(root,1,total);
    }
};
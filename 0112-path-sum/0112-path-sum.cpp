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
bool fun(TreeNode* root,int sum,int targetSum){
    if(root->left==NULL && root->right==NULL){
        if(sum+root->val==targetSum) return true;
        else return false;
    } 
    int l=false; int r=false;
    if(root->left)l= fun(root->left,sum+root->val,targetSum);
    if(root->right)r=fun(root->right,sum+root->val,targetSum);
    return l || r;
}

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return fun(root,0,targetSum);
    }
};
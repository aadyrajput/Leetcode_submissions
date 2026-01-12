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
    return false;
} 
bool a=false,b=false;
if(root->left)a=fun(root->left,sum+root->val,targetSum);
if(root->right)b=fun(root->right,sum+root->val,targetSum);
return a | b;
}
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int sum=0;
        return fun(root,sum,targetSum);
    }
};
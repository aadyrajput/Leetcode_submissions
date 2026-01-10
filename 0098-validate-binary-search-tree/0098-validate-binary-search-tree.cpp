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
bool fun(TreeNode* root,long long min,long long max){
    if(root==NULL)return true;
    if(root->val>=max || root->val<=min)return false;
    return fun(root->left,min,root->val) && fun(root->right,root->val,max);
}
public:
    bool isValidBST(TreeNode* root) {
        return fun(root,LLONG_MIN,LLONG_MAX);
    }
};
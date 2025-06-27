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
bool check(TreeNode* a,long min,long max){
    if(a==NULL) return true;
    if(a->val>=max || a->val<=min) return false;
    return check(a->left,min,a->val) && check(a->right,a->val,max);
}
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return check(root,LONG_MIN,LONG_MAX);
    }
};
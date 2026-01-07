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
int fun(TreeNode* root,int h){
if(root==NULL)return 0;
int lh=fun(root->left,h);
int rh=fun(root->right,h);
return 1+max(lh,rh);
}
public:
    int maxDepth(TreeNode* root) {
        int h=0;
        if(root==NULL)return 0;
        return fun(root,h);
    }
};
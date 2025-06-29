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
int fun(TreeNode* x,int &d){
    if(x==NULL) return 0;
    int lh=fun(x->left,d);
    int rh=fun(x->right,d);
    d=max(d,lh+rh);
    return 1+max(lh,rh);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
     if(root==NULL)return 0;
     int d=0;
     fun(root,d); 
     return d;  
    }
};
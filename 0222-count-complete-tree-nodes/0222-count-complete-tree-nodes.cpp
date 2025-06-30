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
int Left(TreeNode* node){
 int ct=0;
while(node){
    ct++;
    node=node->left;
}
 return ct;
}
int Right(TreeNode* node){
 int ct=0;
while(node){
    ct++;
    node=node->right;
}
 return ct;
}
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=Left(root);
        int rh=Right(root);
       // if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
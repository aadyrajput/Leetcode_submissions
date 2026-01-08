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
bool fun(TreeNode* a,TreeNode* b){
    if(a==NULL && b==NULL)return true;
    if(a==NULL || b==NULL)return false;
    bool a1=a->val==b->val;
    bool a2=fun(a->left,b->right);
    bool a3=fun(a->right,b->left);
    return a1 && a2 && a3;
}
public:
    bool isSymmetric(TreeNode* root) {
       if(root==NULL)return true;
        return fun(root->left,root->right); 
    }
};
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
bool exist(TreeNode* x,int key){
    while(x){
        if(x->val==key)return true;
        else if(x->val<key)x=x->right;
        else x=x->left;
    }
    return false;
}
TreeNode* fun(TreeNode* root){
    if(!root->left)return root->right;
    if(!root->right)return root->left;
    TreeNode* rightCh=root->right;
    TreeNode* leftrightCh=fun2(root->left);
    leftrightCh->right=rightCh;
    return root->left;
}
TreeNode* fun2(TreeNode* x){
    if(x->right==NULL)return x;
    return fun2(x->right);
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!exist(root,key) || root==NULL)return root;

        if(root->val==key)return fun(root);
        TreeNode* temp=root;
        while(temp){
            if(temp->val>key){
                if(temp->left && temp->left->val==key){
                    temp->left=fun(temp->left);
                }
                else temp=temp->left;
            }
            else{
                if(temp->right && temp->right->val==key){
                    temp->right=fun(temp->right);
                }
                else temp=temp->right;
            }
        }        
        return root;
    }
};
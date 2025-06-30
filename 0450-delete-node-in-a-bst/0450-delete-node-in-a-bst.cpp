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
bool exist(TreeNode* root,int key){
    bool flag=false;
    while(root!=NULL){
        if(key==root->val) {flag=true;break;}
        else if(key<root->val) root=root->left;
        else root=root->right;
    }
    return true;
}
TreeNode* fun(TreeNode* root){
    if(root->left==NULL) return root->right;
    if(root->right==NULL) return root->left;
    TreeNode* rightCh=root->right;
    TreeNode* lastR=fun2(root->left);
    lastR->right=rightCh;
    return root->left;
    }
TreeNode* fun2(TreeNode* root){
    if(root->right==NULL)return root; 
    return fun2(root->right);
}

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(!exist(root,key)) return root;

        if(root->val==key){
            return fun(root);
        }

        TreeNode* temp=root;
        while(root!=NULL){
            if(key<root->val){
                if(root->left && key==root->left->val){
                    root->left=fun(root->left);
                }
                else root=root->left;
            }
            else{
                 if(root->right && key==root->right->val){
                    root->right=fun(root->right);
                }
                else root=root->right;
            }
        }

        return temp;
    }
};
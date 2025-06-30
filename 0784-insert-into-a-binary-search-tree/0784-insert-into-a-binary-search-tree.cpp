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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* x= new TreeNode(val);
            return x;
        }
        TreeNode* temp=root;
    while(root!=NULL){
        if(val<root->val){
            if(root->left)root=root->left;
            else{
                TreeNode* x=new TreeNode(val);
                root->left=x; break;
            }
        }
        else{
        if(root->right) root=root->right;
        else{
            TreeNode* x=new TreeNode(val);
            root->right=x; break;
          }
    }
    }
    return temp;
    }
};
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
void inorder(TreeNode* root,vector<int>&v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
void fun(TreeNode* root,int &i,vector<int>&v){
    if(root==NULL) return;
    fun(root->left,i,v);
    root->val=v[i]; i++;
    fun(root->right,i,v);
}

public:
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int i=0;
        fun(root,i,v);
    }
};
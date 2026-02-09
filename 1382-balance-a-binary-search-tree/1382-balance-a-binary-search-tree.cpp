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
void inorder(TreeNode* x,vector<int>&v){
    if(x==NULL)return;
    inorder(x->left,v);
    v.push_back(x->val);
    inorder(x->right,v);
}
TreeNode* build(vector<int>&v,int l,int r){
    if(l>r)return NULL;
    int mid=(l+r)/2;
    TreeNode* node=new TreeNode(v[mid]);
    node->left=build(v,l,mid-1);
    node->right=build(v,mid+1,r);
    return node;
}

public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)return NULL;
        vector<int> v;
        inorder(root,v);
        return build(v,0,v.size()-1);

    }
};
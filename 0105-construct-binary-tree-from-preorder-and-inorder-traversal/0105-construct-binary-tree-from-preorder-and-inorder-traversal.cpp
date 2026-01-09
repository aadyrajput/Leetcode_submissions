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
TreeNode* fun(vector<int>& preorder,int p1,int p2,vector<int>& inorder,int i1,int i2,map<int,int>&m){
    if(p1>p2 || i1>i2)return NULL;
    TreeNode* root=new TreeNode(preorder[p1]);
    int x1=m[root->val];
    int x2=x1-i1;
    root->left=fun(preorder,p1+1,p1+x2,inorder,i1,x1-1,m);
    root->right=fun(preorder,p1+x2+1,p2,inorder,x1+1,i2,m);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return fun(preorder,0,n-1,inorder,0,n-1,m);
    }
};
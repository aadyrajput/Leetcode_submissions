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
TreeNode* fun(vector<int> &preorder,int p1,int p2,
              vector<int> &inorder,int i1,int i2,map<int,int> &m){
    if(p1>p2 || i1>i2)return NULL;
    TreeNode* root= new TreeNode(preorder[p1]);
    int x=m[root->val];
    int y=x-i1;
    root->left=fun(preorder,p1+1,p1+y,inorder,i1,x-1,m);
    root->right=fun(preorder,p1+y+1,p2,inorder,x+1,i2,m);
    return root;
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder; 
        sort(inorder.begin(),inorder.end());
        map<int,int> m;
        for(int i=0;i<inorder.size(); i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=fun(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
};
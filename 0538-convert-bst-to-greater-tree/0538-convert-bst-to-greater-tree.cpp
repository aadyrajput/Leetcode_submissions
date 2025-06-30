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
void inorder(TreeNode* x,vector<int>&ans){
    if(x==NULL) return;
    inorder(x->left,ans);
    ans.push_back(x->val);
    inorder(x->right,ans);
}
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return NULL;
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size();
        map<int,int> m;
        vector<int> suff(n); suff[n-1]=ans[n-1]; m[ans[n-1]]=suff[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i]=suff[i+1]+ans[i];
            m[ans[i]]=suff[i];
        }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz; i++){
            TreeNode* x=q.front();
            q.pop();
            x->val=m[x->val];
            if(x->left)q.push(x->left);
            if(x->right)q.push(x->right);
        }
    }
    return root;

    }
};
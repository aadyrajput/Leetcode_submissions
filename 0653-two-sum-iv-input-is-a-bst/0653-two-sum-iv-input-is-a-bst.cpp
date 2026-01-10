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
void inorder(TreeNode* x,vector<int>&ans){
    if(x==NULL)return;
    inorder(x->left,ans);
    ans.push_back(x->val);
    inorder(x->right,ans);
}
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        vector<int> v;
        inorder(root,v);
        int n=v.size();
        map<int,int> m;
        for(int i=0;i<n; i++){
            m[v[i]]++;
        }
        bool flag=false;
        for(auto it:m){
            int tar=k-it.first;
            if(m.count(tar)==0)continue;
            if(tar==it.first && it.second>=2)flag=true;
            else if(tar!=it.first)if(m.count(tar))flag=true;
        }
        return flag;
    }
};
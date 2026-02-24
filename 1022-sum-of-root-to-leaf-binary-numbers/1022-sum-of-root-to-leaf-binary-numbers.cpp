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
    void fun(TreeNode* root,string &s,vector<string>&v){
          s+=to_string(root->val);
        if(!root->left && !root->right){
            v.push_back(s);
        }
        else{
        if(root->left!=NULL)fun(root->left,s,v);
        if(root->right!=NULL)fun(root->right,s,v);
        }
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        if(root==NULL)return 0;
        string s="";
        fun(root,s,v);
        int ans=0;
        for(auto it:v){
            int sz=it.size();
            string ss=it;
            for(int i=0;i<sz; i++){
                if(ss[i]=='1')ans+=(1<<(sz-1-i));
            }
        }
    return ans;
    }
};
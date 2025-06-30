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
        vector<int> ans;
        inorder(root,ans);
        map<int,int> m;
        for(auto it:ans)m[it]++;
        bool flag=false;
        for(auto it:m){
            int tar=k-it.first;
            if(m.count(tar)==0)continue;
            if(tar==it.first){
                if(m.count(tar)>=2) flag=true;
            }
            else{
                if(m.count(tar)!=0) flag=true;
            }
        }
    return flag;
    }
};
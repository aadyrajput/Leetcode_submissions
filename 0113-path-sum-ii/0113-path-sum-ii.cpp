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
void fun(TreeNode* root,int sum,int targetSum,vector<int> &v,vector<vector<int>>&ans){
if(root==NULL)return;
    sum+=root->val;
    v.push_back(root->val);
if(root->left==NULL && root->right==NULL){
    if(sum==targetSum) ans.push_back(v);
} 
else{
fun(root->left,sum,targetSum,v,ans);
fun(root->right,sum,targetSum,v,ans);
}
v.pop_back();
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        int sum=0;
        vector<int> v;
        fun(root,sum,targetSum,v,ans);
        return ans;
    }
};
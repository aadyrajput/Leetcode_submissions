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
void fun(TreeNode* root,int sum,int targetSum,vector<int> temp, vector<vector<int>>&ans){
    if(root==NULL) return ;
    temp.push_back(root->val);
    sum+=root->val;
    if(root->left==NULL && root->right==NULL){
        if(sum==targetSum){
            ans.push_back(temp);
        }
        return;
    } 
    
    if(root->left){ fun(root->left,sum,targetSum,temp,ans);}
    if(root->right){fun(root->right,sum,targetSum,temp,ans);}
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        vector<int> temp;
        fun(root,0,targetSum,temp,ans);
        return ans;
    }
};
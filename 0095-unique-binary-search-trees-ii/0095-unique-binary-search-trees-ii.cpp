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
vector<TreeNode*> fun(int st,int end,map<pair<int,int>,vector<TreeNode*>> &dp){
    vector<TreeNode*> ans;
    if(st>end) {ans.push_back(NULL); return ans; }
    if(dp.find({st,end})!=dp.end())  return dp[{st,end}];

    for(int i=st; i<=end; i++){
        vector<TreeNode*> left=fun(st,i-1,dp);
        vector<TreeNode*> right=fun(i+1,end,dp);

        for(auto it:left){
            for(auto it2:right){
                TreeNode* root= new TreeNode(i,it,it2);
                    ans.push_back(root);            
                }
        }
    }
    return dp[{st,end}]=ans;
}

public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>> dp;
        return fun(1,n,dp);
    }
};
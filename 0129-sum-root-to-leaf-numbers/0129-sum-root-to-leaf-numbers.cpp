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
void fun(TreeNode* root,string s,vector<string>&ans){
    s+=to_string(root->val);
    if(!root->left && !root->right){
        ans.push_back(s);
        return;
    }
    if(root->left)fun(root->left,s,ans);
    if(root->right)fun(root->right,s,ans);
}
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<string> ans;
        fun(root,"",ans);
        int sum=0;
        for(int i=0; i<ans.size(); i++){
            sum+= stoi(ans[i]);
        }
    return sum;
    }
};
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
string serealise(TreeNode* root,map<string,int> &m,vector<TreeNode*>&ans){
    if(root==NULL)return "#";
    string l=serealise(root->left,m,ans);
    string r=serealise(root->right,m,ans);

    string s=l+','+r+','+to_string(root->val);
    if(m[s]==1)ans.push_back(root);
    m[s]++;
    return s;
}
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        if(!root)return ans;
        map<string,int> m;
        serealise(root,m,ans);
        return ans;
    }
};
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* x=q.front();
                q.pop();
                temp.push_back(x->val);
                if(x->left!=NULL)q.push(x->left);
                if(x->right!=NULL)q.push(x->right);
            }            
            ans.push_back(temp);
        }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
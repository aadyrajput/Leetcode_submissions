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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        if(root==NULL)return {};
        for(auto it:to_delete){
            st.insert(it);
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*> ans;
        // if(st.find(root->val)!=st.end()){

        // }

        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            if(x->left){
                q.push(x->left);
                if(st.find(x->left->val)!=st.end())x->left=NULL;
            }
            if(x->right){
                q.push(x->right);
            if(st.find(x->right->val)!=st.end())x->right=NULL;
            }
             if(st.find(x->val)!=st.end()){
                if(x->left && st.find(x->left->val)==st.end()){ans.push_back(x->left); x->left=NULL;}
                if(x->right && st.find(x->right->val)==st.end()){ans.push_back(x->right);x->right=NULL;}
            }
        }
        if(st.find(root->val)==st.end()) ans.push_back(root);
    return ans;
    }
};
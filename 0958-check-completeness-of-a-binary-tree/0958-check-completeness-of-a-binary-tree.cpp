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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
    while(!q.empty()){
        TreeNode* x=q.front();
        q.pop();
        if(x==NULL) flag=true;
        else{
            if(flag) return false;
        q.push(x->left);
        q.push(x->right);
        }
    }
    return true;
    }
};
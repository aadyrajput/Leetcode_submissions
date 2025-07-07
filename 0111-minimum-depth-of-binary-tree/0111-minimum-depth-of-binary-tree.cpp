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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MAX; int ct=0;
        while(!q.empty()){
            int sz=q.size(); ct++;
            for(int i=0;i<sz; i++){
                TreeNode* x=q.front();
                q.pop();
                if(!x->left && !x->right) ans=min(ans,ct);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right); 
            }
        }
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
void parent(TreeNode* x,unordered_map<TreeNode*,TreeNode*> &m){
    queue<TreeNode*>q;
    q.push(x);
    while(!q.empty()){
        TreeNode* xx=q.front(); q.pop();
        if(xx->left){
            m[xx->left]=xx; q.push(xx->left);
        }
        if(xx->right){
            m[xx->right]=xx; q.push(xx->right);
        }
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL)return {};
        unordered_map<TreeNode*,TreeNode*> m;
        parent(root,m);

        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        int lev=0;
        while(!q.empty()){
            int sz=q.size();
            if(lev==k) break;
            for(int i=0;i<sz; i++){
                TreeNode* x=q.front();
                q.pop();
                if(x->left && !vis[x->left]){
                    q.push(x->left); vis[x->left]=true;
                }
                if(x->right && !vis[x->right]){
                    q.push(x->right); vis[x->right]=true;
                }
                if(m[x] && !vis[m[x]]){
                    q.push(m[x]); vis[m[x]]=true;
                }
            }lev++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val); q.pop();
        }
       
        return ans;
    }
};
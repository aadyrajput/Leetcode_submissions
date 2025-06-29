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
void parent_mark(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &par){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
      TreeNode* x=q.front();
      q.pop();
      if(x->left){
        par[x->left]=x;
        q.push(x->left);
      }
      if(x->right){
        par[x->right]=x;
        q.push(x->right);
      }
    }
}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        parent_mark(root,par);

        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int t=0; 
        while(!q.empty()){
             int sz=q.size();
                if(t==k) break;
            for(int i=0;i<sz;i++){
                TreeNode* x=q.front();
                q.pop();
                if(x->left && !vis[x->left]){
                    q.push(x->left); vis[x->left]=true;
                }
                if(x->right && !vis[x->right]){
                    q.push(x->right); vis[x->right]=true;
                }
                 if(par[x] && !vis[par[x]]){
                    q.push(par[x]); vis[par[x]]=true;
                }
            }
            t++;
          }
    vector<int>ans;
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
        return ans;
    }
};
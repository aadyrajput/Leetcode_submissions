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
long long fun(TreeNode* x){
    if(x==NULL)return 0;
   x->val= x->val+fun(x->left)+fun(x->right);
    return x->val;
}
public:
    int maxProduct(TreeNode* root) {
     long long totsum=fun(root);
     queue<TreeNode*> q;
     q.push(root);
     long long ans=0;
     while(!q.empty()){
        TreeNode* x=q.front();
        q.pop();
        //if(node==NULL)continue;
        long long z=(totsum-x->val)*1ll*x->val;
        ans=max(ans,z);
        if(x->left)q.push(x->left);
        if(x->right)q.push(x->right);
     }
     const int M=1e9+7;
    return ans%M;
    }
};
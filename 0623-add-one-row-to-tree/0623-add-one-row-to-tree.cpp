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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* x=new TreeNode(val);
            x->left=root;
            return x;
        }
        int d=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            d++;
            for(int i=0;i<sz;i++){
                TreeNode* x=q.front();
                q.pop();
                if(d==depth){
                    TreeNode* l=new TreeNode(val);
                    TreeNode* r=new TreeNode(val);
                    TreeNode* xl=x->left;
                    TreeNode* xr=x->right;
                    x->left=l; x->right=r;
                    l->left=xl; r->right=xr;  
                }
                else{
                    if(x->left)q.push(x->left);
                    if(x->right)q.push(x->right);
                }
            }
        }
    return root;

    }
};
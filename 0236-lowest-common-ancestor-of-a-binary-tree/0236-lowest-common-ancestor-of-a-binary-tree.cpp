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
TreeNode* fun(TreeNode* node,TreeNode* p,TreeNode* q){
 if(node==NULL)return NULL;
 if(node==p || node==q)return node;
 TreeNode* lh=fun(node->left,p,q);
 TreeNode* rh=fun(node->right,p,q);
 if(lh==NULL)return rh;
 else if(rh==NULL) return lh;
 else return node;
}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root,p,q);
    }
};

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
bool fun(TreeNode*p, TreeNode*q){
    if(p==NULL || q==NULL){
        if(p==q)return true;
        else return false;
    }
    return fun(p->left,q->left) && fun(p->right,q->right) && (p->val==q->val) ;
}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        return fun(p,q);
    }
};
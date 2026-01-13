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
void fun(TreeNode*x,vector<int>&v){
    if(x==NULL)return;
    if(x->left==NULL && x->right==NULL){
        v.push_back(x->val);
        return;
    }
    fun(x->left,v);
    fun(x->right,v);
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int> v1,v2;
         fun(root1,v1);
         fun(root2,v2);
         if(v1==v2)return true;
         return false;
    }
};
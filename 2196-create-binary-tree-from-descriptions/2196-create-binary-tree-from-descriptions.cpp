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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> childs;
        set<int> nodes;
        int n=descriptions.size();
        map<int,TreeNode*> m;
        for(int i=0;i<n;i++){
            int par=descriptions[i][0],
            ch=descriptions[i][1],
            isleft=descriptions[i][2];
            if(m.find(par)==m.end()) m[par]=new TreeNode(par);
            if(m.find(ch)==m.end()) m[ch]=new TreeNode(ch);
            childs.insert(ch); nodes.insert(par); nodes.insert(ch);
            TreeNode* parr=m[par];
            TreeNode* chh=m[ch];
            if(isleft==0) parr->right=chh;
            else parr->left=chh;
        }
        int root;
        for(auto it:nodes){
            if(childs.find(it)==childs.end()) {
                root=it; break;
            }
        }
        TreeNode* ans=m[root];
        return ans;

    }
};
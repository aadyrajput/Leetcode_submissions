/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string ans="";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* x=q.front();
                q.pop();
                if(x==NULL) ans.append("#,");
                else{
                    ans.append(to_string(x->val)+',');
                }

                if(x!=NULL){
                    q.push(x->left);
                    q.push(x->right); }
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                x->left==NULL;
            }
            else{
                TreeNode* leftN= new TreeNode(stoi(str));
                x->left=leftN;
                q.push(leftN);
            }

            getline(s,str,',');
            if(str=="#"){
                x->right==NULL;
            }
            else{
                TreeNode* rightN= new TreeNode(stoi(str));
                x->right=rightN;
                q.push(rightN);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
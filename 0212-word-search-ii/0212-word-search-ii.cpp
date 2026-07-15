struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))return false;
            node=node->get(word[i]); 
        }
        return true;
    }
};

int dr[4]={-1,0,1,0};
int dc[4]={0,-1,0,1};

void fun(int i,int j, Node* node, string &temp, vector<vector<char>>& board,
        vector<vector<int>>& vis, vector<string>& ans){
    
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j]) return;
    char ch=board[i][j];

    if(!node->containsKey(ch)) return;

    vis[i][j]=1;
    temp.push_back(ch);
    node=node->get(ch);

    if(node->isEnd()){
        ans.push_back(temp);
        node->flag=false;      // avoid duplicates
    }

    for(int k=0;k<4;k++){
        int ni=i+dr[k];
        int nj=j+dc[k];
        fun(ni,nj,node,temp,board,vis,ans);
    }

    vis[i][j]=0;
    temp.pop_back();
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       int m=board.size();
       int n=board[0].size();
       Trie tr;
        for(auto it:words){
            tr.insert(it);
        }
     vector<string> ans;

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<vector<int>> vis(m,vector<int>(n,0));
            string temp="";
            fun(i,j,tr.root,temp,board,vis,ans);
        }
      }

    return ans;
    }
};
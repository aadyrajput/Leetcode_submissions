class disjointSet{
public:
vector<int> par,size;
 disjointSet(int n){
    par.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++)par[i]=i;
 }
int findPar(int x){
    if(x==par[x])return x;
    return par[x]=findPar(par[x]);
}
void unionn(int u,int v){
    int up=findPar(u);
    int vp=findPar(v);
    if(up==vp)return;
    if(size[up]>size[vp]){
        size[up]+=size[vp];
        par[vp]=up;
    }
    else{
           size[vp]+=size[up];
        par[up]=vp;
    }
}

};

bool isCycle(int x,vector<bool> &vis,vector<bool>&pathvis,vector<vector<int>>&adj){
    vis[x]=true;
    pathvis[x]=true;
    for(auto it:adj[x]){
        if(vis[it]){
            if(pathvis[it])return true;
        }
        else{
            if(isCycle(it,vis,pathvis,adj))return true;
        }
    }

    pathvis[x]=false;
    return false;
}

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        disjointSet ds(n);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){adj[i].push_back(leftChild[i]); ds.unionn(i,leftChild[i]);}
             if(rightChild[i]!=-1){adj[i].push_back(rightChild[i]);ds.unionn(i,rightChild[i]);}
        }

        int ct=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i)ct++;
        }
        if(ct>1)return false;

        vector<bool> vis(n,false),pathvis(n,false);
        for(int i=0;i<n;i++){
            if(isCycle(i,vis,pathvis,adj))return false;
        }

         map<int,int> m;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                m[it]++;
                if(m[it]>1)return false;
            }
        }

        set<pair<int,int>> st;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                int mina=min(i,it), maxa=max(i,it);
                if(st.find({mina,maxa})!=st.end())return false;
                st.insert({mina,maxa});
            }
        }
        
        return true;
    }
};
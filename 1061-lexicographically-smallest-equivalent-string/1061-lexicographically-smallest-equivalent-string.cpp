class DisjointSet{
    public:
    vector<int> rank,size,par;
    DisjointSet(int n){
        rank.resize(n+1,1);
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int findPar(int x){
        if(x==par[x])return x;
        return par[x]=findPar(par[x]);
    }
    void unionBySize(int u,int v){
        int up=findPar(u);
        int vp=findPar(v);
        if(up==vp)return;
        if(up>vp){
            par[up]=vp;
            size[vp]+=size[up];
        }
        else{
            par[vp]=up;
            size[up]+=size[vp];
        }
        // if(up==vp)return;
        // if(size[up]<size[vp]){
        //     par[up]=vp;
        //     size[vp]+=size[up];
        // }
        // else{
        //      par[vp]=up;
        //     size[up]+=size[vp];
        // }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for(int i=0;i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                ds.unionBySize(s1[i]-'a',s2[i]-'a');
            }
        }
        string ans="";
        for(int i=0;i<baseStr.size(); i++){
            int x=baseStr[i]-'a';
            int xx=ds.findPar(x);
            ans+=char('a'+xx);
        }
    return ans;
    }
};
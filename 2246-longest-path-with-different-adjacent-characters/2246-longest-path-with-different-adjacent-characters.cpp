class Solution {
public:
    int ans;

     int fun(int x,int par,vector<vector<int>>&adj,string &s){
        int lar=0;
        int seclar=0;

        for(auto it:adj[x]){
            if(it==par)continue;
            int z=fun(it,x,adj,s);
             if(s[it]==s[x])continue;
            if(z>seclar)seclar=z;
            if(seclar>lar)swap(lar,seclar);
        }

        int neeche_milgaya=1+lar+seclar;
        int koi_ekacha=max(lar,seclar)+1;
        int keval_rootacha=1;
        ans=max({ans,neeche_milgaya,koi_ekacha,keval_rootacha});
        return max(koi_ekacha,keval_rootacha);
    }
    int longestPath(vector<int>& parent, string s) {
        ans=0;
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(parent[i]==-1)continue;
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
         fun(0,-1,adj,s);
        return ans;

    }
};
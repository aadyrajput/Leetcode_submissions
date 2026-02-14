class DisjointSet{
public:
    vector<int> par,size;
    DisjointSet(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int findPar(int u){
        if(u==par[u]) return u;
        return par[u]=findPar(par[u]);
    }
    bool unionBySize(int u, int v){
        int up=findPar(u);
        int vp=findPar(v);
        if(up==vp) return false;
        if(size[up]<size[vp]){
            size[vp]+=size[up];
            par[up]=vp;
        }
        else{
            size[up]+=size[vp];
            par[vp]=up;
        }
        return true;
    }
};

class Solution {
public:

    int kruskal(int n, vector<vector<int>>& edges,
                int skip, int force){

        DisjointSet ds(n);
        int sum=0;
        int cnt=0;

        // 🔥 force include edge
        if(force!=-1){
            sum+=edges[force][2];
            ds.unionBySize(edges[force][0],edges[force][1]);
            cnt++;
        }

        for(int i=0;i<edges.size();i++){
            if(i==skip) continue;

            if(ds.unionBySize(edges[i][0],edges[i][1])){
                sum+=edges[i][2];
                cnt++;
            }
        }

        if(cnt!=n-1) return 1e9;  // not MST
        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {

        int m=edges.size();

        // attach index
        for(int i=0;i<m;i++)
            edges[i].push_back(i);

        sort(edges.begin(),edges.end(),
            [](auto &a,auto &b){
                return a[2]<b[2];
            });

        int minsum=kruskal(n,edges,-1,-1);

        vector<int> critical, pseudo;

        for(int i=0;i<m;i++){

            // 🔥 check critical
            if(kruskal(n,edges,i,-1)>minsum){
                critical.push_back(edges[i][3]);
            }
            else{
                // 🔥 check pseudo
                if(kruskal(n,edges,-1,i)==minsum)
                    pseudo.push_back(edges[i][3]);
            }
        }

        return {critical,pseudo};
    }
};

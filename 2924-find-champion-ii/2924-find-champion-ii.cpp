class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        int ct=0; int city=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){ct++; city=i;}
            if(ct>1)return -1;
        }
        return city;
    }
};
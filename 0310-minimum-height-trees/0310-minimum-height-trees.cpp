class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges){
            int a=it[0], b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++; indegree[b]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==1)q.push(i);
    }
    int nodes=n;

    while(nodes>2){
        int sz=q.size();
        nodes-=sz;
        for(int i=0;i<sz; i++){
        int z=q.front();
        q.pop();
        for(auto it:adj[z]){
            indegree[it]--;
            if(indegree[it]==1)q.push(it);
        }
     }
    }

    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    return ans;

    }
};
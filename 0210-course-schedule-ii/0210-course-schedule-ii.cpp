class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
         vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n; i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            topo.push_back(x);
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }    
    if(topo.size()==n)return topo;
    vector<int> temp;
    return temp;
    }
};
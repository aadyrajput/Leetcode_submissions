class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<set<int>> ans(n);
        while(!q.empty()){
            int z=q.front();
            q.pop();
            for(auto it:adj[z]){
                indegree[it]--;
                for(auto itt:ans[z])ans[it].insert(itt);
                ans[it].insert(z);
                if(indegree[it]==0)q.push(it);
            }
        }

        vector<vector<int>>res(n);
        for(int i=0;i<ans.size(); i++){
            if(ans[i].size()==0)continue;
            for(auto itt:ans[i]){
                res[i].push_back(itt);
            }
        }
        return res;
        

    }
};
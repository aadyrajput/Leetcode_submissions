class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> inorder(n+1,0);
        for(auto it:relations){
            adj[it[0]].push_back(it[1]);
            inorder[it[1]]++;
        }
        queue<int> q;
        for(int i=1;i<n+1; i++){
            if(inorder[i]==0)q.push(i);
        }
        vector<int> time_copy=time;
        int res=0;
        while(!q.empty()){
            int z=q.front();
            res=max(res,time_copy[z-1]);
            q.pop();
            for(auto it:adj[z]){
                inorder[it]--;
                time_copy[it-1]=max(time_copy[it-1],time[it-1]+time_copy[z-1]);
                if(inorder[it]==0)q.push(it);
            }
        }
    return res;
    }
};
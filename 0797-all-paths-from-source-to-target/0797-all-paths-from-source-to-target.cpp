class Solution {
private:
void fun(int i,vector<int>&v,vector<vector<int>>&ans,vector<vector<int>>&graph,vector<int>&vis){
    if(i==graph.size()-1){
        ans.push_back(v);
        return;
    }
    for(auto it:graph[i]){
        if(vis[it])continue;
        v.push_back(it);
        vis[it]=1;
        fun(it,v,ans,graph,vis);
        vis[it]=0;
        v.pop_back();
    }
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v; v.push_back(0);
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vis[0]=1;
        fun(0,v,ans,graph,vis);
        return ans;
    }
};
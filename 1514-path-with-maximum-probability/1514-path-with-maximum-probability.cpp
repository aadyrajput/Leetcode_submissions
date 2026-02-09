class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
     vector<double>dist(n,-1);
     vector<vector<pair<int,double>>> adj(n);
     for(int i=0;i<edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
     }
     dist[start_node]=1.00000;
     priority_queue<pair<double,int>> pq;
     pq.push({1.00000,start_node});
     while(!pq.empty()){
        int x=pq.top().second;
        double d=pq.top().first;
        pq.pop();
        for(auto it:adj[x]){
            int adjnode=it.first;
            double adjwt=it.second;
        if(dist[adjnode]<d*adjwt){
            dist[adjnode]=d*adjwt;
            pq.push({dist[adjnode],adjnode});
        }
     }
    }
    double res=dist[end_node];
    if(res==-1)return 0.00000;
    return res;
    }
};
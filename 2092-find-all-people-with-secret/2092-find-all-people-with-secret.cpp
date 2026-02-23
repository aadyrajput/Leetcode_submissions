class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:meetings){
          int a=it[0], b=it[1], c=it[2];
          adj[a].push_back({b,c});
          adj[b].push_back({a,c});
        }

        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; 
        pq.push({0,firstPerson});
        pq.push({0,0});
        dist[firstPerson]=0; dist[0]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int z=pq.top().second;
            pq.pop();
            if(dist[z]<d)continue;
            for(auto it:adj[z]){
                int adjnode=it.first; int tt=it.second;
                if(tt>=d && tt<dist[adjnode]) {
                    pq.push({tt,adjnode});
                    dist[adjnode]=tt;
                } 
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dist[i]!=1e9)ans.push_back(i);
        }
        return ans;
    }
};
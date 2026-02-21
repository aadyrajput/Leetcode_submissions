class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> dist;
    int nn;
    Graph(int n, vector<vector<int>>& edges) {
        nn=n;
        adj.resize(nn);
        dist.resize(nn,vector<int>(nn,INT_MAX));
        for(int i=0;i<nn;i++)dist[i][i]=0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            dist[it[0]][it[1]]=it[2];
        }
        for(int k=0;k<nn;k++){
            for(int i=0;i<nn;i++){
                for(int j=0;j<nn;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
        dist[edge[0]][edge[1]]=min(dist[edge[0]][edge[1]],edge[2]);
           for(int k=0;k<nn;k++){
            for(int i=0;i<nn;i++){
                for(int j=0;j<nn;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

    }
    
    int shortestPath(int node1, int node2) {
        if(dist[node1][node2]==INT_MAX)return -1;
        return dist[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
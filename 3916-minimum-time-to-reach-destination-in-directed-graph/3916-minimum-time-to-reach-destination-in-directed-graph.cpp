class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n == 1)return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<vector<int>>> adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1], it[2], it[3]});
            if(it[0] == 0)
            {
                pq.push({it[2], it[1]});
            }
        }

        vector<int> vis(n, 0);

        while(!pq.empty())
        {
            auto [q, e] = pq.top();
            pq.pop();

            int xx = q + 1;
            if(e == n - 1)return xx;

            if(vis[e] == 1)continue;
            vis[e] = 1;

            for(auto it: adj[e])
            {
                int desi = it[0];
                int lauda1 = it[1];
                int lauda2 = it[2];

                if(lauda1 <= xx && xx <= lauda2)
                {
                    pq.push({xx, desi});
                }
                else if(xx < lauda1)
                {
                    pq.push({lauda1, desi});
                }
            }
        }
        return -1;
    }
};
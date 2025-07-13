class Solution {
class DisjointSet {
public:
    vector<int> rank, par, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        par.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if (node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }

    int unionByRank(int u, int v) {
        int ultpar_u = findPar(u);
        int ultpar_v = findPar(v);
        if (ultpar_u == ultpar_v) return 1;
        if (rank[ultpar_u] < rank[ultpar_v]) par[ultpar_u] = ultpar_v;
        else if (rank[ultpar_u] > rank[ultpar_v]) par[ultpar_v] = ultpar_u;
        else {
            par[ultpar_v] = ultpar_u;
            rank[ultpar_u]++;
        }
        return 0;
    }
};

public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int, pair<int, int>>> v;
        for (auto& it : edges) {
            v.push_back({it[2], {it[0], it[1]}});
        }
        sort(v.begin(), v.end());

        DisjointSet ds(n);
        vector<int> ans;

        for (auto& it : v) {
            int wt = it.first;
            int u = it.second.first;
            int vv = it.second.second;
            if (ds.findPar(u) != ds.findPar(vv)) {
                ans.push_back(wt);
                ds.unionByRank(u, vv);
            }
        }

        sort(ans.rbegin(), ans.rend());
        for (int i = 0; i < k - 1 && !ans.empty(); ++i) {
            ans.erase(ans.begin());
        }

        return ans.empty() ? 0 : ans[0];
    }
};

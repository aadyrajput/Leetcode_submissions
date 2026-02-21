class Solution {
public:
    vector<string> res;
    unordered_map<string, multiset<string>> adj;

    void dfs(string src) {
        while (!adj[src].empty()) {
            string next = *adj[src].begin();   // smallest lexical
            adj[src].erase(adj[src].begin());  // remove edge
            dfs(next);
        }
        res.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &it : tickets) {
            adj[it[0]].insert(it[1]);
        }

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
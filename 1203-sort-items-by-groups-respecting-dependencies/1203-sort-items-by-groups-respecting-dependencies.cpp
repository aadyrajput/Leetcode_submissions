class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;
        vector<int> res;

        for(int i = 0; i < graph.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front(); q.pop();
            res.push_back(node);

            for(int nei : graph[node]){
                if(--indegree[nei] == 0)
                    q.push(nei);
            }
        }

        if(res.size() != graph.size())
            return {};

        return res;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // Assign unique groups to -1
        for(int i = 0; i < n; i++){
            if(group[i] == -1)
                group[i] = m++;
        }

        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(m);
        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(m, 0);

        for(int i = 0; i < n; i++){
            for(int prev : beforeItems[i]){
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                if(group[prev] != group[i]){
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        if(itemOrder.empty() || groupOrder.empty())
            return {};

        unordered_map<int, vector<int>> groupedItems;
        for(int item : itemOrder)
            groupedItems[group[item]].push_back(item);

        vector<int> result;
        for(int g : groupOrder){
            for(int item : groupedItems[g])
                result.push_back(item);
        }

        return result;
    }
};

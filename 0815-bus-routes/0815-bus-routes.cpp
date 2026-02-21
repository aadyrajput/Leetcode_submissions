class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
     int n=routes.size();
     unordered_map<int,vector<int>> node_tobus;
     for(int i=0;i<routes.size(); i++){
         vector<int> temp=routes[i];
        for(int j=0;j<temp.size(); j++){
            node_tobus[temp[j]].push_back(i);
        }
     }
     int ans=0;
     set<int> st;
     queue<int> q;
     q.push(source);
     while(!q.empty()){
        int sz=q.size();
        for(int k=0;k<sz; k++){
        int node=q.front();
        q.pop();
        if(node==target)return ans;
        vector<int> buses=node_tobus[node];
        for(int i=0;i<buses.size(); i++){
            if(st.find(buses[i])!=st.end())continue;
            st.insert(buses[i]);
            for(auto it:routes[buses[i]]){
                q.push(it);
            }
        }
    }
        ans++;
     }
     return -1;


    }
};
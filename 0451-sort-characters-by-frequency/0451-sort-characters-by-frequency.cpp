class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto it:s)m[it]++;

        priority_queue<pair<int,int>>pq;
        for(auto it:m)pq.push({it.second,it.first});
       string ans;
       while(!pq.empty()){
            int ct=pq.top().first;
            char x=pq.top().second;
            pq.pop();
            while(ct--)ans+=x;
       }
        return ans;
    }
};
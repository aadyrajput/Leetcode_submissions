class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> m;
        for(auto it:s)m[it]++;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int z=pq.top().first; char x=pq.top().second;
            while(z--)ans+=x;
            pq.pop();
        }

        return ans;
    }
};
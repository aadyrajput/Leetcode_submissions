class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>m;
        for(auto it:tasks)m[it]++;
        priority_queue<pair<int,char>> pq;
        for(auto it:m)pq.push({it.second,it.first});
        int ans=0;
    while(!pq.empty()){
       priority_queue<pair<int,char>> p2;
       int z=n+1;
       if(pq.top().first==1){
        ans+=pq.size(); break;
       }
       ans+=(n+1);
       while(z-- && !pq.empty()){
         int a=pq.top().first; char b=pq.top().second;
         pq.pop();
         if(a!=1)p2.push({a-1,b});
       }
       while(!p2.empty()){pq.push(p2.top()); p2.pop();}
    }

    return ans;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        map<char,int> m;
        for(auto it:s)m[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        string res="";

        while(pq.size()>=2){
          int ct1=pq.top().first; char c1=pq.top().second;
          pq.pop();
          int ct2=pq.top().first; char c2=pq.top().second;
          pq.pop();
          res+=c1; res+=c2;
          if(ct1>1)pq.push({ct1-1,c1});
          if(ct2>1)pq.push({ct2-1,c2});
        }

        if(pq.size()==0)return res;
        if(pq.size()==1 && pq.top().first==1){
            res+=pq.top().second; 
            return res;
        }
    return "";
    }
};
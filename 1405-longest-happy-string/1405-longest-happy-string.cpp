class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>> pq;
        if(a!=0) pq.push({a,'a'});
        if(b!=0)pq.push({b,'b'});
        if(c!=0)pq.push({c,'c'});

        string ans="";
        while(!pq.empty()){
            int z=pq.top().first; char zz=pq.top().second;
            pq.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==zz && ans[ans.size()-2]==zz){
                if(pq.size()==0)break;
                    int z1=pq.top().first; char zz1=pq.top().second;
                    pq.pop(); ans+=zz1;
                    if(z1>1)pq.push({z1-1,zz1});
                    pq.push({z,zz});
            }
            else {ans+=zz; 
                if(z>1)pq.push({z-1,zz});
            }
        }
        return ans;

    }
};
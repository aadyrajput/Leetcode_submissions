class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
            map<int,int> m,m1,m2;
            int mina=INT_MAX;
            for(auto it:basket1){mina=min(mina,it); m[it]++; m1[it]++;}
            for(auto it:basket2){mina=min(mina,it);  m[it]++; m2[it]++;}

            for(auto it:m){
                if(it.second%2!=0)return -1;
            } 
            priority_queue<int,vector<int>,greater<>> pq1;
            priority_queue<int> pq2;

            for(auto it:m1){
                int z=m[it.first];
                int the=it.second; int oth=z-the;
                int zz=(the-oth)/2;
                if(the>oth){
                    for(int i=0;i<zz; i++)pq1.push(it.first);
                }
            }

             for(auto it:m2){
                int z=m[it.first];
                int the=it.second; int oth=z-the;
                int zz=(the-oth)/2;
                if(the>oth){
                    for(int i=0;i<zz; i++)pq2.push(it.first);
                }
            }

            long long ans=0;
            while(!pq1.empty() && !pq2.empty()){
                int z1=pq1.top(), z2=pq2.top();
                pq1.pop(); pq2.pop();
                int mn=min(z1,z2);
                if(mn<=2*mina) ans+=mn;
                else ans+=(mina*2);
            }
    return ans;
    }
};
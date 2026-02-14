class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<>> pq;
        vector<int> v={2,3,5};
        map<long long,int> m;
        long long ans=0;
    m[1]=1; pq.push(1);
    for(int i=0;i<n;i++){
        ans=pq.top();
        pq.pop();
        for(auto it:v){
            if(m.find(it*1ll*ans)==m.end()){
                m[it*ans]++; pq.push(it*1ll*ans);
            }
        }
    }

    return ans;
    }
};
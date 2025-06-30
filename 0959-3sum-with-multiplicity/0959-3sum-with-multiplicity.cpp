class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
     int M=1e9+7;
     unordered_map<int,int> m;
     for(auto it:arr)m[it]++;
    long ans=0;
    for(auto it:m){
        for(auto itt:m){
            int a=it.first; int b=itt.first;
            int c=target-a-b;
            if(!m.count(c))continue;

            if(a==b && b==c){
                long x=m[a]*1ll*(m[a]-1)*1ll*(m[a]-2)/6;
                ans+=x;
                   //   ans += 1L * m[a] * (m[a] - 1) * (m[a] - 2) / 6;
            }
            else if(a==b && a!=c){
                long y=(m[a]*1ll*(m[a]-1))/2; y=y*1ll*m[c];
                ans+=y;
            }
            else if(a<b && b<c){
                long z=m[a]*1ll*m[b]*1ll*m[c];
                ans+=z;
            }
        }
    }

    return ans%M;
    }
};
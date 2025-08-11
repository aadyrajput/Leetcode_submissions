class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
     vector<int> v;
     int x=1;
    while(n){
        if(n%2!=0){
            v.push_back(x);
        } 
        x*=2;
        n=n/2;
    }
    int M=1e9+7;
    vector<int> ans;
    for(auto it:queries){
        int z=1;
        int l=it[0]; int r=it[1];
        for(int i=l; i<=r; i++){
            z=(z*1ll*v[i])%M;
        }
        ans.push_back(z);
    }
    return ans;
    }
};
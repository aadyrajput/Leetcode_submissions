class Solution {
public:
    long long countPairs(vector<string>& words) {
        map<vector<int>,int> m;
        for(int i=0;i<words.size(); i++){
            vector<int> v;
            for(int j=0;j<words[i].size()-1; j++){
                int z=words[i][j]-words[i][j+1];
                if(z<0)z=26+z;
                v.push_back(z);
            }
         m[v]++;
        }
        long long ans=0;
        for(auto it:m){
            int z=it.second;
            long long x=(z*1ll*(z-1))/2;
            ans+=x;
        }
    return ans;
    }
};
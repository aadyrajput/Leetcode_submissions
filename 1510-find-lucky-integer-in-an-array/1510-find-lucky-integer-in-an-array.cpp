class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        for(auto it:arr)m[it]++;
        int ans=-1;
        for(auto it:m){
            if(it.first==it.second) ans=it.first;
        }
        return ans;
    }
};
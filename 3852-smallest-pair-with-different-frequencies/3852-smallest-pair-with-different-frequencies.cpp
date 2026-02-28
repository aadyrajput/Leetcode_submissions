class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        set<int> st;
        for(auto it:m)st.insert(it.second);
        if(st.size()==1)return {-1,-1};
        int a=0,b=0; int f=0;
        bool flag=false;
        for(auto it:m){
            if(flag==false){
            a=it.first; f=it.second;
            flag=true; continue;
            }
            if(it.second!=f){
                b=it.first; break;
            }

        }

        return {a,b};
    }
};
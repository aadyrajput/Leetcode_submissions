class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(int i=0;i<bank.size(); i++){
            int ct=0; int sz=bank[i].size();
            for(int j=0; j<sz; j++){
                if(bank[i][j]=='1') ct++;
            }
            if(ct==0) continue;
            else v.push_back(ct);
        }
        if(v.size()==0 ||v.size()==1)return 0;
        int ans=0;
        for(int i=0;i<v.size()-1; i++){
            ans+=(v[i]*1LL*v[i+1]);
        }
        return ans;

    }
};
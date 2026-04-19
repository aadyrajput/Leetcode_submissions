class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> arrr;
        for(auto it:arr){
            map<char,int> mp;
            for(auto itt:it) mp[itt]++;
            if(mp.size()==it.size())arrr.push_back(it);
        }

        int n=arrr.size();
        int ans=0;
        int mask=1<<n;
        for(int i=0;i<mask; i++){
             int seen=0;               // mask to check duplicate string
             int ct=0;
            for(int j=0;j<arrr.size(); j++){
                bool flaa=false;
                if((1<<j)&i){
                    for(auto it:arrr[j]){
                        int zz=it-'a';
                        if(seen &(1<<zz)){flaa=true; break;}
                        seen= seen | (1<<zz); ct++; 
                    }
                }
                if(flaa)break;
                ans=max(ans,ct);
            }
        }

        return ans;
    }
};
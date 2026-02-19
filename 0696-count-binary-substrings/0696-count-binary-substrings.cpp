class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        int ct=1;
        int n=s.size();
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])ct++;
            else{
                v.push_back(ct);
                ct=1;
            }
        }
        v.push_back(ct);
        int ans=0;
        for(int i=0;i<v.size()-1; i++){
            int z=min(v[i],v[i+1]);
            ans+=z;
        }
    return ans;
    }
};
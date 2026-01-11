class Solution {
public:
    int residuePrefixes(string s) {
        int ct=0;
        int ans=0;
        map<char,int> m;
        for(int i=0;i<s.size(); i++){
            m[s[i]]++;
            int z=m.size();
            int zz=(i+1)%3;
            if(z==zz)ans++;
        }
    return ans;
    }
};
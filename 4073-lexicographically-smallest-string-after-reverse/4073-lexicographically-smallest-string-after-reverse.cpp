class Solution {
public:
    string lexSmallest(string s) {
        string ans=s;
        for(int i=0; i<s.size(); i++){
            string zz=s;
            reverse(zz.begin(),zz.begin()+i+1);
            ans=min(ans,zz);
            zz=s;
            reverse(zz.begin()+i+1,zz.end());
            ans=min(ans,zz);
        }
        return ans;



    }
};
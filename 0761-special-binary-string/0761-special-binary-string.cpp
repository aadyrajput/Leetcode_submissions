class Solution {
public:
    string makeLargestSpecial(string s) {
        int ct=0;
        int ptr=0;
        vector<string> v;
        for(int i=0;i<s.size(); i++){
            if(s[i]=='1')ct++;
            else ct--;
            if(ct==0){
                v.push_back("1"+makeLargestSpecial(s.substr(ptr+1,i-ptr-1))+"0");
                ptr=i+1;
            }
        }
        sort(v.begin(),v.end(),greater<string>());
        string ans="";
        for(auto it:v)ans+=it;
        return ans;
    }
};
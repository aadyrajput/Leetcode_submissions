class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> m;
        int ans=0;
        int p1=0; int n=s.size();
        for(int i=0;i<s.size(); i++){
          m[s[i]]++;
          if(m.size()<3)continue;
            while(m.size()==3){
            ans+=(n-i);
            m[s[p1]]--;
            if(m[s[p1]]==0)m.erase(s[p1]);
            p1++;
           }
        }
        return ans;

    }
};
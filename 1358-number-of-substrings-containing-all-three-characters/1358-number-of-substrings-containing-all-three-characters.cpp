class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int ptr=0;
        map<char,int> m; 
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
            if(m.size()<3)continue;
            while(m.size()==3){
                ans+=(n-i);
                m[s[ptr]]--;
                if(m[s[ptr]]==0)m.erase(s[ptr]);
                ptr++;
            }
        }
        return ans;
    }   
};
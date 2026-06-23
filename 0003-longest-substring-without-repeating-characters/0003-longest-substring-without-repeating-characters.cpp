class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int p1=-1;
       map<char,int> mp;
       int ans=0;
       for(int i=0;i<s.size();i++){
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]++;
            ans=max(ans,i-p1); continue;
        }
           while(mp.find(s[i])!=mp.end()){
            p1++;
            mp[s[p1]]--;
            if(mp[s[p1]]==0)mp.erase(s[p1]);
           }
           mp[s[i]]++;
       }
    return ans;
    }
};
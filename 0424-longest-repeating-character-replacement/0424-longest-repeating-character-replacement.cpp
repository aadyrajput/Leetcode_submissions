class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        int ans=0; int left=0;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            int maxa=-1; int sum=0;
            for(auto it:m){
                sum+=it.second;
                maxa=max(maxa,it.second);
            }
            sum-=maxa;
            if(sum<=k){
                ans=max(ans,i-left+1);
            }
            else{
                m[s[left]]--;
                left++;
                ans=max(ans,i-left+1);               
            }
        }
        return ans;
    }
};
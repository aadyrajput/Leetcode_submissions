class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0;
        int n=s.size();
        int waste=0;
        for(auto it:s){
            if(it==' ') waste++;
            if(it>='0' && it<='9') waste++;
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u')v++;
        }
        int c=n-v-waste;
        if(c==0)return 0;
        int ans=floor(v/c);
        return ans;
    }
};
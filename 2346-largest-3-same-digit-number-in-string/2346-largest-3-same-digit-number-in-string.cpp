class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=-1; string s=num;
        for(int i=0;i<s.size()-2; i++){
            if(s[i]==s[i+1] && s[i]==s[i+2]){
                int x=s[i]-'0';
                int num=(x*100)+(x*10)+x;
                ans=max(ans,num);
            }
        }
        if(ans==-1)return "";
        if(ans==0)return "000";
        return to_string(ans);
        
    }
};
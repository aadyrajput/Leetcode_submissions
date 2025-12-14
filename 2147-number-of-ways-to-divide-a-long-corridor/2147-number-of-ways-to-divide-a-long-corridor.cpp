class Solution {
public:
    int numberOfWays(string corridor) {
        int ct=0;
        string s=corridor;
        for(auto it:corridor)if(it=='S')ct++;
        if(ct%2!=0 ||ct==0)return 0;
        int M=1e9+7;
        if(ct==2)return 1;
        int ans=1;
           int flag=0; int ctr=1;
          int ind=-1;
          for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='S'){
                ind=i; break;
            }
          } 

        for(int i=0;i<=ind; i++){
            if(flag==2){
                if(s[i]=='S'){
                    ans=(ans*1ll*ctr)%M;
                    flag=0; ctr=1;
                }
                else ctr++;
            }
            if(s[i]=='S') flag++;
        }
    return ans;
    }
};
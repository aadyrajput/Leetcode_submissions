class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans=0;
        for(int i=0; i<=31; i++){
            int z1=a&(1<<i);
            int z2=b&(1<<i);
            int z3=c&(1<<i);
            int ct=0; if(z1!=0)ct++; if(z2!=0)ct++;
            
            if(ct==0){
                if(z3==0) continue;
                else ans++;
            }
            else{
              if(z3!=0)continue;
              ans+=ct;
            }
        }
        return ans;
    }
};
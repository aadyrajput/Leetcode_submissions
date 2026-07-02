class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int z1=__builtin_popcount(num1);
        int z2=__builtin_popcount(num2);
        int ans=0;
        if(z1==z2)return num1;

         for(int i=30; i>=0;i--){
            int z=1<<i;
            if(num1&z){
            ans=(ans | (1<<i)); z2--;
            }
            if(z2==0)break;
        }

          for(int i=0;i<30;i++){
            if(z2==0)break;
            int z=1<<i;
            if((ans&z)==0){
                ans=ans|(1<<i); z2--;
                }
            }          
        return ans;
    }
};
class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<int> v(31,0);
        for(int i=1;i<31; i++){
            v[i]=(1<<i)-1;
        }
        int ans=0;
        bool flag=false;
        for(int i=30; i>=0; i--){
            if(n&(1<<i)){
               if(flag==false){flag=true; ans+=v[i+1];}
               else{flag=false; ans-=v[i+1];}
            }
        }
    return ans;

    }
};
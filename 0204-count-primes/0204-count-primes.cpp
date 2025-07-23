class Solution {
public:
    int countPrimes(int n) {
        if(n==2)return 0;
        if(n==3) return 1;
     vector<bool> prime(n+1,true);
     prime[0]=false; prime[1]=false;
     int ans=0;
        for(int i=2; i<n; i++){
            if(prime[i]){
                ans++;
                for(int j=2*i; j<n; j+=i){
                    prime[j]=false;
                }
            }
        }
return ans;
    }
};
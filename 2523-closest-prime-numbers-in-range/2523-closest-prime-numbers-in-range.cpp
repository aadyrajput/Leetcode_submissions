class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2; i*i<right+1; i++){
           if(isPrime[i]){
            for(int j=i*i; j<right+1; j+=i){
                isPrime[j]=false;
            }
           }
        }
        
        vector<int> v;
        for(int i=left;i<=right;i++){
            if(isPrime[i]) v.push_back(i);
        }
        if(v.size()<2) return {-1,-1};
        int mina=v[1]-v[0];
        vector<int> ans={v[0],v[1]};
        for(int i=1;i<v.size(); i++){
            if(v[i]-v[i-1]<mina){
                mina=v[i]-v[i-1]; ans={v[i-1],v[i]};
            }
        }
    return ans;
    }
};
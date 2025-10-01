class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int a=ans;
        int b=numExchange;
        ans+=(a/b);
        while(a>=b){
            int z=a/b;
            int zz=a%b;
            ans+=((z+zz)/b);
            a=z+zz;
        }

    return ans;

    }
};
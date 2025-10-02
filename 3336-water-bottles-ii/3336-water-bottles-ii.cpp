class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int a=numBottles;
        int b=numExchange;
        int ans=a;
        while(a>=b){
            int z=a/b;
            int zz=a%b;
            ans++;
            a-=b; a++;
            b++;
        }
    return ans;
    }
};
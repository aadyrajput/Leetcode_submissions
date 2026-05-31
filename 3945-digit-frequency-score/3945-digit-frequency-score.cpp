class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> m;
        while(n){
            m[n%10]++;
            n/=10;
        }
        int sum=0;
        for(auto it:m){
            sum+=(it.first*it.second);
        }
        return sum;
    }
};
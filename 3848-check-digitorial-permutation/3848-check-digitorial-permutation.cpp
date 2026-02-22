class Solution {
public:
    int fact(int x){
        if(x<=1)return 1;
        return x*fact(x-1);
    }
    bool isDigitorialPermutation(int n) {
        multiset<int> m;
        int z=n;
        while(z){
            m.insert(z%10);
            z=z/10;
        }
        int ans=0;
        for(auto it:m){
            ans+=fact(it);
        }
        multiset<int> mm;
        while(ans){
            mm.insert(ans%10);
            ans/=10;
        }
        if(m==mm)return true;
        return false;


    }
};
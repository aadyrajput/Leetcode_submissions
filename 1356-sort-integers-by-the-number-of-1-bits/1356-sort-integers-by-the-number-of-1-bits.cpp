class Solution {
public:
    bool static comp(int a,int b){
        int z1=__builtin_popcount(a);
        int z2=__builtin_popcount(b);
        if(z1==z2)return a<b;
        return z1<z2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
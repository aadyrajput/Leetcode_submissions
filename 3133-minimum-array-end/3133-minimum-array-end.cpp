class Solution {
public:
    vector<int> fun(int z){
        vector<int> v;
        while(z){
            if(z%2==0)v.push_back(0);
            else v.push_back(1);
            z=z/2;
        }
        return v;
    }
    long long minEnd(int n, int x) {
        if(n==1)return x;
        int tar=n-1;
        long long ans=x;

        vector<int> v=fun(tar);
        int j=0; int sz=v.size();
        for(int i=0;i<63; i++){
            long long z=1LL<<i;
            if(ans&z)continue;
            if(v[j]==0)j++;
            else {ans=ans|z; j++;}
        if(j==v.size()) break;
        }

    return ans;
    }
};
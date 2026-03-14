class Solution {
public:
    void fun(int i,int n,string z,vector<string>&ans){
        if(i==n){
            ans.push_back(z);
            return;
        }
        if(z.empty() || z.back()!='a') fun(i+1,n,z+'a',ans);
        if(z.empty() || z.back()!='b') fun(i+1,n,z+'b',ans);
        if(z.empty() || z.back()!='c') fun(i+1,n,z+'c',ans);
    }

    string getHappyString(int n, int k) {
        int z=1<<(n-1);
        z=z*3;
        if(k>z)return "";
        string temp="";
        vector<string> v;
        fun(0,n,temp,v);
        sort(v.begin(),v.end());
        return v[k-1];
    }
};
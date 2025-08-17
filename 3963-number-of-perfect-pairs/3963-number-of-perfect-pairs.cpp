class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<int>v;
        long long ct=0;
        for(auto it:nums){
            if(it!=0) v.push_back(abs(it));
            else ct++;
        }
        sort(v.begin(),v.end());
        long long ans=0;
        ans+=(ct*1ll*(ct-1))/2;
        for(int i=0;i<v.size()-1;i++){
            int x=v[i];
             int a=lower_bound(v.begin(),v.end(),x*2)-v.begin();
            int b=upper_bound(v.begin(),v.end(),x*2)-v.begin();
            if(a!=v.size() && v[a]==x*2){
                a=b-1;
            }
            if(a!=b)ans+=(a-i);
            else ans+=(a-i-1);
        }
        return ans;
    }
};
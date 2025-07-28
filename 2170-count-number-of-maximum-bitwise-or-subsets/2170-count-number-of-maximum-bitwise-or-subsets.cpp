class Solution {
private:
void fun(int ind,map<int,int> &m,vector<int> v,vector<int>&nums){
if(ind==nums.size()){
    int orr=0;
    for(int i=0;i<v.size(); i++)orr= (orr|v[i]);
    m[orr]++;
    return;
}
v.push_back(nums[ind]);
fun(ind+1,m,v,nums);
v.pop_back();
fun(ind+1,m,v,nums);
}

public:
    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;
    fun(0,m,v,nums);
    int ans=0;
    for(auto it:m){
        ans=it.second;
    }
    return ans;

    }
};
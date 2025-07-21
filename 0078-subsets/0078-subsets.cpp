class Solution {
private:
void fun(int i,vector<int> temp,vector<int>&nums,set<vector<int>>&st){
    if(i==nums.size()){
        st.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    fun(i+1,temp,nums,st);
    temp.pop_back();
    fun(i+1,temp,nums,st);

}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        fun(0,temp,nums,st);
        vector<vector<int>> ans;
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};
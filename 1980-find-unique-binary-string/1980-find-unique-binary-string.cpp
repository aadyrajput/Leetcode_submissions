class Solution {
public:
    void fun(int i, int n,string temp,vector<string>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        fun(i+1,n,temp+"0",ans);
        fun(i+1,n,temp+"1",ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> ans;
        int n=nums.size();
        string temp;
        fun(0,n,temp,ans);
        set<string> st;
        for(auto it:nums)st.insert(it);
        string res="";
        for(auto it:ans){
            if(st.find(it)==st.end()){res=it; break;}
        }
        return res;

    }
};
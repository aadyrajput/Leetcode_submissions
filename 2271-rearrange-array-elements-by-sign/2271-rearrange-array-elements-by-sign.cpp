class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1,q2;
        for(auto it:nums){
            if(it<0) q1.push(it);
            else q2.push(it);
        }
        vector<int> ans;
        while(!q1.empty() && !q2.empty()){
            ans.push_back(q2.front());
            q2.pop();
            ans.push_back(q1.front());
            q1.pop();
        }
        return ans;

    }
};
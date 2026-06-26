class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
         int m=nums1.size(), n=nums2.size();
        vector<vector<int>> ans;
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        set<pair<int,int>> st;
        
        pq.push({nums1[0]+nums2[0],0,0});
        st.insert({0,0});
        
        while(k-- && !pq.empty()){
            auto [sum,i,j]=pq.top();
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            
            if(i+1<m && !st.count({i+1,j})) {
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                st.insert({i+1,j});
            }
            if(j+1<n && !st.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                st.insert({i,j+1});
            }
        }
        
        return ans;
    }
};
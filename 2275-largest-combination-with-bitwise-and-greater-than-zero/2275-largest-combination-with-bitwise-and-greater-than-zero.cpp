class Solution {
public:
    int largestCombination(vector<int>& candidates) {
      int ans=0;
      for(int j=0;j<=25; j++){
            int ct=0;
            int nums=1<<j;
        for(int i=0;i<candidates.size(); i++){
            if(candidates[i]&nums)ct++;
        }
        ans=max(ans,ct);
      }
    return ans;
    }
};
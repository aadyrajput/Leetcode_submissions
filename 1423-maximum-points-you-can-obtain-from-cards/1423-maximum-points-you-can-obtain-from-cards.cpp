class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        long long tot=0;
        for(auto it:cardPoints)tot+=it;
        
        int tarsize=n-k;
        int sum=0; 
        for(int i=0;i<tarsize; i++){
            sum+=cardPoints[i];
        }
        int ans=sum; int ptr=0;
        for(int i=tarsize;i<n; i++){
            sum+=cardPoints[i];
            sum-=cardPoints[ptr];
            ptr++;
            ans=min(ans,sum);
        }

        int res=tot-ans;
        return res;
    }
};
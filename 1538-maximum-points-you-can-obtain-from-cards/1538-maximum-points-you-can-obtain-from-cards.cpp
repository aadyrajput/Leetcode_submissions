class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0; int maxsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k; i++){
            sum+=cardPoints[i];
        }
        maxsum=max(maxsum,sum);
        int l=k-1; int r=n-1;
        while(l>=0){
            sum+=cardPoints[r];
            sum-=cardPoints[l];
            r--; l--;
            maxsum=max(maxsum,sum);
        }
        return maxsum;

    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k; i++){
            lsum+=cardPoints[i];
        }
        int maxsum=lsum;
        int l=k-1; int r=n-1;
        while(l>=0){
            lsum-=cardPoints[l];
            rsum+=cardPoints[r];
            l--; r--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;

    }
};
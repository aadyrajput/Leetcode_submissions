class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m=landStartTime.size(), n=waterStartTime.size();
        int mina=INT_MAX;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int landS=landStartTime[i];
                int durS=landDuration[i];
                int waterS=waterStartTime[j];
                int durW=waterDuration[j];

                int landend=landS+durS;
                if(landend>=waterS)mina=min(mina,landend+durW);
                else mina=min(mina,waterS+durW);
                int waterend=waterS+durW;
                if(waterend>=landS)mina=min(mina,waterend+durS);
                else mina=min(mina,landS+durS);
            }
        }
        return mina;
    }
};
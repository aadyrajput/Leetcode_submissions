class Solution {
public:
    bool static comp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);

        int maxa=intervals[0][1], mina=maxa-1;
        int ans=2;
        for(int i=1; i<n; i++){
            int a=intervals[i][0], b=intervals[i][1];
            if(maxa<a){
                mina=b-1, maxa=b; ans+=2;
            }
            else if(a>mina){
                ans++; mina=maxa,maxa=b;
           }
        }
    return ans;
    }
};
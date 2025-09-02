class Solution {
private:
static bool fun(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])return a[1]>b[1];
    return a[0]<b[0];
}
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        
        sort(points.begin(),points.end(),fun);

        for(int i=0; i<n; i++){
            int bot=INT_MIN; int top=points[i][1];
            for(int j=i+1; j<n; j++){
                int zz=points[j][1];
                if(zz>bot && zz<=top){
                    ans++;
                    bot=zz;
                    if(bot==top)break;
                }
            }

        }
    return ans;
    }
};
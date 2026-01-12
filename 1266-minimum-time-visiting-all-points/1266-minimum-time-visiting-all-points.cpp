class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
     int ct=0;
     int n=points.size();
     for(int i=0;i<n-1; i++){
        int disx=abs(points[i][0]-points[i+1][0]);
        int disy=abs(points[i][1]-points[i+1][1]);
        int mina=min(disx,disy);
        ct+=mina;
        ct+=(disx-mina); ct+=(disy-mina);
     }
    return ct;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int ct=1;
        int prevE=points[0][1];

    for(int i=1;i<n;i++){
        int currS=points[i][0], currE=points[i][1];
        if(currS>prevE){
            ct++;
             prevE=currE;
        } 
        else{
            prevE=min(prevE,currE);
        }   
    }

    return ct;
    }
};
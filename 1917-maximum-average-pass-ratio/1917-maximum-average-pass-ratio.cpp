class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        int n=classes.size();

        for(int i=0;i<n;i++){
            double x=(double)classes[i][0]/(double)classes[i][1];
            double y=(double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({y-x,i});
        }
        while(extraStudents--){
            auto it=pq.top();
            pq.pop();
            int i=it.second;
            classes[i][0]+=1;
            classes[i][1]+=1;
             double x=(double)classes[i][0]/(double)classes[i][1];
            double y=(double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({y-x,i});
        }
        double ans=0.0;
        for(auto it:classes)ans+=(double)it[0]/it[1];
        return ans/n;


    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }                  /////// push index otheriwise it will be lost after sorting
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        int timer=tasks[0][0];
        vector<int> ans;
        for(int i=0;i<tasks.size();i++){
            if(tasks[i][0]<=timer) {pq.push({tasks[i][1],tasks[i][2]}); continue;}
            while(!pq.empty() && tasks[i][0]>timer){
                timer+=pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            }
            if(timer<tasks[i][0])timer=tasks[i][0];     //CPU idle
            pq.push({tasks[i][1],tasks[i][2]});
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop(); 
        }
    return ans;


    }
};
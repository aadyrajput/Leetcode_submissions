class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0;
        for(auto it:events){
            ans=max(ans,it[2]);
        }
        sort(events.begin(),events.end());
        map<int,int> m;
        for(auto it:events){
            m[it[1]]=0;
        }
        for(int i=0;i<events.size(); i++){
            m[events[i][1]]=max(m[events[i][1]],events[i][2]);
        }
        vector<int> vsec,vval;
        for(auto it:m){
            vsec.push_back(it.first);
            vval.push_back(it.second);
        }
        for(int i=1; i<vval.size(); i++){
            vval[i]=max(vval[i],vval[i-1]);
        }
        int sum=0;
        for(int i=1;i<events.size(); i++){
            int z=events[i][2];
            int lbound=lower_bound(vsec.begin(),vsec.end(),events[i][0])-vsec.begin();
            if(lbound==0){
                if(vsec[0]<events[i][0])ans=max(ans,z+vval[0]);
                continue;
            }
            lbound--;
            ans=max(ans,z+vval[lbound]);
        }

        ans=max(ans,sum);
        return ans;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(auto it:tasks){
            v[it-'A']++;
        }
        sort(v.begin(),v.end());

        int maxa=v[25];
        int gaddhe=maxa-1;
        int slots=gaddhe*n;

        for(int i=24; i>=0; i--){
            slots-=min(v[i],gaddhe);
        }
        if(slots>0)return tasks.size()+slots;
        return tasks.size();
    }
};
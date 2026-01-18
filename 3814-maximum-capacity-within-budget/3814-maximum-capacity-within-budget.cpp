class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int ans=0;
        int n=costs.size();
        for(int i=0; i<n; i++){
            if(costs[i]<budget)ans=max(ans,capacity[i]);
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n; i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());
        vector<int> costs2,cap2;
        for(auto it:v){
            costs2.push_back(it.first);
            cap2.push_back(it.second);
        }
        vector<int> caphas(n,0);
        caphas[0]=cap2[0];
        for(int i=1; i<n; i++){
            caphas[i]=max(caphas[i-1],cap2[i]);
        }
        for(int i=0;i<n; i++){
             if(v[i].first>=budget)break;
             int find=budget-v[i].first;
            int j=lower_bound(costs2.begin(),costs2.end(),find)-costs2.begin();
            j--;
            j=min(j,i-1);
            if(j>=0)ans=max(ans,cap2[i]+caphas[j]);
        }
        return ans;

    }
};
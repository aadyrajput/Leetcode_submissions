class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int k=17; k>=0;k--){
            vector<vector<int>> temp(m);
            int z=(1<<k);
            bool flag=false;
            for(int i=0;i<grid.size(); i++){
                for(auto it:grid[i]){
                    if((z&it)==0)temp[i].push_back(it);
                }
               if(temp[i].empty()){flag=true; break;} 
            }
            if(flag)ans=ans | z;
            else grid=temp;
        }
        return ans;
    }
};
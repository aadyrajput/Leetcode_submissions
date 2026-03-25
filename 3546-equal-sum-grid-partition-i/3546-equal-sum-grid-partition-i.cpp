class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<long long> hor,ver;
        long long toth=0, totv=0;
        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            toth+=sum;
            hor.push_back(sum);
        }

        for(int j=0;j<n;j++){
            long long sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
            }
            totv+=sum;
            ver.push_back(sum);
        }

        long long temp=0;
        if(toth%2==0){
        for(int i=0;i<hor.size(); i++){
                temp+=hor[i];
                if(temp==toth/2)return true;
        }
        }

          temp=0;
        if(totv%2==0){
        for(int i=0;i<ver.size(); i++){
                temp+=ver[i];
                if(temp==totv/2)return true;
        }
        }
        return false;



    }
};
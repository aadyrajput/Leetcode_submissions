class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> has(n+1,0);
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int ct=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)ct++;
                else break;
            }
            has[ct]++;
            v[i]=ct;
        }
        int extra=has[n];
        for(int i=n-1; i>=0; i--){
            if(has[i]==0){
                if(extra>0){extra--; continue;}
                else return -1;
            }
            else extra+=(has[i]-1);
        }

        int ans=0;
    for(int i=0;i<n;i++){
        int need=n-1-i;
        int j=i;
        while(j<n && v[j]<need)j++;
        while(j>i){
            swap(v[j],v[j-1]);
            j--;
            ans++;
        }
    }

    return ans;
    }
};
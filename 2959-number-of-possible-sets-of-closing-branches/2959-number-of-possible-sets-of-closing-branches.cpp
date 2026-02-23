class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans=0;
        int subsets=1<<n;

        for(int ii=0;ii<subsets;ii++){
            set<int> st;
            for(int j=0;j<n; j++){
                if(ii&(1<<j))st.insert(j);
            }

          vector<vector<int>> dist(n,vector<int>(n,1e9));

          for(auto it:roads){
            int a=it[0], b=it[1], c=it[2];
            if(st.find(a)!=st.end())continue;
            if(st.find(b)!=st.end())continue;
            dist[a][b]=min(dist[a][b],c);
            dist[b][a]=min(dist[b][a],c);
          }
          for(int i=0;i<n;i++){
            if(st.find(i)==st.end())dist[i][i]=0;
          }

          for(int k=0; k<n; k++){
            for(int i=0;i<n; i++){
              for(int j=0;j<n;j++){
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
              }
            }
          }
          
          bool flag=false;
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(st.find(i)!=st.end() || st.find(j)!=st.end())continue;
                if(dist[i][j]>maxDistance)flag=true;
            }
          }
          if(!flag)ans++;
        }

    return ans;
    }
};
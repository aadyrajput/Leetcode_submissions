class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26,vector<long long>(26,1e18));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        int n=cost.size();
        for(int i=0;i<n;i++){
            if(cost[i]<dist[original[i]-'a'][changed[i]-'a'])
                dist[original[i]-'a'][changed[i]-'a']=cost[i];
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=1e18 && dist[k][j]!=1e18)
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i])continue;
            if(dist[source[i]-'a'][target[i]-'a']==1e18) return -1;
            ans+=dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
                

    }
};
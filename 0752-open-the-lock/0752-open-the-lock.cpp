class Solution {
public:
    bool fun(string &s1,string &s2){
        int ct=0;
        for(int i=0;i<4; i++){
            if(s1[i]!=s2[i])ct++;
        }
    if(ct==1)return true;
    return false;
    }
    int openLock(vector<string>& deadends, string target) {
        

        set<int> st;
        for(auto it:deadends)st.insert(stoi(it));
        if(st.find(0)!=st.end())return -1;

        vector<vector<int>> adj(10000);
        for(int i=0;i<=9999; i++){
            int a=i;
            string s1=to_string(i);
            reverse(s1.begin(),s1.end());
            while(s1.size()<4)s1+='0';
            reverse(s1.begin(),s1.end());

            string s2=s1;
            for(int i=0;i<4;i++){
                char cc=char(s1[i]+1);
                if(s1[i]=='9') cc='0';
                s2[i]=cc;
                if(fun(s1,s2)){
                    adj[stoi(s1)].push_back(stoi(s2));
                     adj[stoi(s2)].push_back(stoi(s1));
                }
                s2=s1;
                 cc=char(s1[i]-1);
                if(s1[i]=='0') cc='9';
                s2[i]=cc;
                if(fun(s1,s2)){
                    adj[stoi(s1)].push_back(stoi(s2));
                     adj[stoi(s2)].push_back(stoi(s1));
                }
            }
        }

        vector<int> dist(10000,1e9);
        dist[0]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int no=pq.top().second;
            if(no==stoi(target))return dist[no];
            pq.pop();
            if(dist[no]<d)continue;
        for(auto it:adj[no]){
            if(st.find(it)!=st.end())continue;
            if(dist[it]>d+1){
                dist[it]=d+1;
                pq.push({dist[it],it});
            }
        }
     }
    return -1;
    }
};
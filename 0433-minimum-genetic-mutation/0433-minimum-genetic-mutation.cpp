class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        set<string> st;
        for(auto it:bank){
            st.insert(it);
        }
        vector<char> v={'A','C','G','T'};
        q.push({startGene,0});
        while(!q.empty()){
            string z=q.front().first;
            int ct=q.front().second;
            q.pop();
            if(z==endGene)return ct;
            for(int i=0;i<z.size(); i++){
                string zz=z;
                for(int j=0;j<4;j++){
                    zz[i]=v[j];
                    if(st.find(zz)!=st.end()){
                        st.erase(zz);
                        q.push({zz,ct+1});
                    }
                }
            }
        }
    return -1;

    }
};
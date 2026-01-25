class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        q.push({beginWord,0});
        while(!q.empty()){
            string z=q.front().first;
            int ct=q.front().second;
            q.pop();
            if(z==endWord)return ct+1;
            for(int i=0;i<z.size(); i++){
                string zz=z;
                for(char j='a';j<='z';j++){
                    zz[i]=j;
                    if(st.find(zz)!=st.end()){
                        st.erase(zz);
                        q.push({zz,ct+1});
                    }
                }
            }
        }
    return 0;
    }
};
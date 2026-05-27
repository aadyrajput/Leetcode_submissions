class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        map<int,int>m;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]<=90)continue;
            m[word[i]-'a']=i;
        }

        set<char> st;
        for(int i=0;i<n;i++){
            if(word[i]>90)continue;
            if(st.find(word[i])!=st.end())continue;
            st.insert(word[i]);
            if(m.find(word[i]-'A')==m.end())continue;
            int z=m[word[i]-'A'];
            if(z<i)ans++;
        }


        return ans;
    }
};
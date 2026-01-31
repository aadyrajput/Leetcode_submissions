class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target=='z')return letters[0];
        set<int> st;
        for(auto it:letters){
            st.insert(it-'a');
        }
        vector<int> v;
        for(auto it:st)v.push_back(it);
        int z=upper_bound(v.begin(),v.end(),target-'a')-v.begin();
        if(z==v.size())return letters[0];
        return char(v[z]+'a');
    }
};
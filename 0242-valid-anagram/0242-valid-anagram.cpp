class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1,m2;
        for(auto it:s) m1[it]++;
        for(auto it:t) m2[it]++;
        if(m1==m2)return true;
        return false;
    }
};
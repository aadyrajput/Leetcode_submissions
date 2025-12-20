class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ct=0;
        int n=strs.size();
        int m=strs[0].size();
        for(int i=0;i<m; i++){
            vector<char> v;
            for(int j=0;j<n;j++){
                v.push_back(strs[j][i]);
            }
            if(!is_sorted(v.begin(),v.end()))ct++;
        }

        return ct;
    }
};
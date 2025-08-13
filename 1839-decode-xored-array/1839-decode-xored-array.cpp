class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int last=first;
        for(int i=0;i<encoded.size(); i++){
            int x=encoded[i];
            int y=x^last;
            last=y;
            ans.push_back(last);
        }
        return ans;
    }
};
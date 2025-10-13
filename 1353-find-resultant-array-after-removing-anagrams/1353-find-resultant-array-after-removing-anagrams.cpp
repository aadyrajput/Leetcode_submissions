class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> v;
        int n=words.size();
        for(auto it:words){
            string z=it;
            sort(z.begin(),z.end());
            v.push_back(z);
        }
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<n; i++){
            if(v[i]==v[i-1]) continue;
            else ans.push_back(words[i]);
        }
        return ans;


    }
};
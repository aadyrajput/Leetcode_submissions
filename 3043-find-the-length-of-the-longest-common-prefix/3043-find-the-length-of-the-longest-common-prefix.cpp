class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> m;
        for(auto it:arr1){
            string x=to_string(it);
            string z="";
            for(int i=0;i<x.size(); i++){
                z+=x[i];
                m.insert(z);
            }
        }
        int ans=0;
    for(auto it:arr2){
        string x=to_string(it);
         string z="";
        for(int i=0;i<x.size(); i++){
                z+=x[i];
            if(m.find(z)!=m.end())ans=max(ans,i+1);
        }
    }
    return ans;
    }
};
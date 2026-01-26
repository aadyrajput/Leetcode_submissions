class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            ans=min(ans,abs(arr[i]-arr[i+1]));
        }
        
        vector<vector<int>> res;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==ans) {
                vector<int> v={arr[i],arr[i+1]};
                res.push_back(v);
            }
        }
    return res;

    }
};
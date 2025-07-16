class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n=numRows;
        vector<int> first; first.push_back(1);
        ans.push_back(first);
        if(n==1)return ans;
        vector<int> second; second.push_back(1); second.push_back(1);
        ans.push_back(second);
        n-=2;
        vector<int> prev=second;
        for(int i=0; i<n; i++){
            vector<int>temp;
            temp.push_back(1);
            for(int i=0; i<prev.size()-1; i++){
                temp.push_back(prev[i]+prev[i+1]);
            }
            temp.push_back(1);
            prev=temp;
            ans.push_back(temp);
        }
        return ans;
    }
};
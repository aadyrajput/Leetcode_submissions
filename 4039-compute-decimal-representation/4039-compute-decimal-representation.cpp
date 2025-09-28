class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int ct=0;
        while(n){
            int z=n%10;
            z=z*pow(10,ct);
            ct++;
            if(z!=0)ans.push_back(z);
            n=n/10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
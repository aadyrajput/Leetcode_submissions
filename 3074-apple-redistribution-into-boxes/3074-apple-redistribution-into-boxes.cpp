class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int ct=0;
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=0;
        for(auto it:apple)
            sum+=it;
    for(auto it:capacity){
        sum-=it;
        ct++;
        if(sum<=0) break;
    }
    return ct;
    }
};
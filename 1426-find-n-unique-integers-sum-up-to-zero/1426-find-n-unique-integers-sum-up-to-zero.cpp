class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if(n%2==0){
            for(int i=1; i<=n/2; i++){
                v.push_back(i);
                v.push_back(-i);
            }
        }
        else{
            int x=n/2;
            for(int i=-x; i<=x; i++){
                v.push_back(i);
            }
        }
return v;
    }
};
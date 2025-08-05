class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ct=0; int n=fruits.size();
        for(int i=0;i<n; i++){
            for(int j=0;j<n; j++){
                if(fruits[i]<=baskets[j]){
                    ct++; baskets[j]=0;
                    break;
                }
            }
        }
        return n-ct;


    }
};
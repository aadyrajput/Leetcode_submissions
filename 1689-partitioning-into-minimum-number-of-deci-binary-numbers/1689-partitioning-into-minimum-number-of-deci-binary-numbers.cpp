class Solution {
public:
    int minPartitions(string n) {
        int maxa=0;
        for(auto it:n){
            maxa=max(maxa,it-'0');
        }
        return maxa;
    }
};
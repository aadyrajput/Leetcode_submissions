class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p1=0; int p2=0;
        int ct=0;
        int m=players.size(); int n=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(p1<m && p2<n){
           if(players[p1]<=trainers[p2]){p1++; p2++; ct++;}
           else p2++;
        }
        return ct;
    }
};
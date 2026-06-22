class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ct=INT_MAX;
        map<char,int> m;
        for(auto it:text){
            m[it]++;
        }
        string z="balon";
        for(auto it:z){
            if(m.find(it)==m.end()){
                ct=0; break;
            }
            if(it=='l' || it=='o'){
                ct=min(ct,m[it]/2);
            }
            else ct=min(ct,m[it]);
        }

        if(ct==INT_MAX)return 0;
        return ct;
    }
};
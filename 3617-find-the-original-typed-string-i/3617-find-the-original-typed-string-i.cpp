class Solution {
public:
    int possibleStringCount(string word) {
        map<int,int> m;
        int ans=1; int ct=0;
        for(int i=0;i<word.size()-1; i++){
            if(word[i]==word[i+1]){
                ct++;
            }
            else{
                ans+=ct;
                ct=0;
            }
        }
        ans+=ct;
        return ans;


    }
};
class Solution {
public:
    vector<vector<pair<int,int>>> ans;

    bool check(int row,int col,vector<int>&queen){
        for(int i=0;i<row; i++){
            int prow=i;
            int pcol=queen[i];
            if(pcol==col || abs(prow-row)==abs(pcol-col))return false;
        }
        return true;
    }
    void fun(int i,vector<int>&queen,vector<pair<int,int>>&temp,int n){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int col=0;col<n; col++){
            if(check(i,col,queen)){
                queen[i]=col;
                temp.push_back({i,col});
                fun(i+1,queen,temp,n);
                queen[i]=-1;
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> queen(n,-1);
        vector<pair<int,int>> temp;

        fun(0,queen,temp,n);

        vector<vector<string>> res;
        string dum;
        for(int i=0;i<n;i++)dum.push_back('.');

        for(auto it:ans){
            vector<string> v;
            for(auto itt:it){
                string s=dum;
                s[itt.second]='Q';
                v.push_back(s);
            }
            res.push_back(v);
        }
        return res;
    }
};
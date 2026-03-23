class Solution {
public:
    bool check(int row,int col,vector<int>&queen){
        for(int i=0;i<row; i++){
            int prow=i;
            int pcol=queen[i];
            if((pcol==col) || abs(pcol-col)==abs(prow-row))return false;
        }
        return true;
    }

    void fun(int i,int n,vector<pair<int,int>>&v, vector<vector<pair<int,int>>> &vv,    
             vector<int> &queen){
        if(i==n){
            vv.push_back(v);
        }

        for(int col=0; col<n; col++){
            if(check(i,col,queen)){
                queen[i]=col;
                v.push_back({i,col});
                fun(i+1,n,v,vv,queen);
                queen[i]=-1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<pair<int,int>> v;
       vector<vector<pair<int,int>>> vv;
    vector<int> queen(n,-1);
    vector<vector<string>> ans;

    fun(0,n,v,vv,queen);

    for(auto it:vv){
        map<int,int> m;
        for(auto itt:it){
            m[itt.first]=itt.second;
        }
        vector<string> tt;
        string s="";
        for(int i=0;i<n;i++)s+=".";
        for(auto it:m){
            s[it.second]='Q';
            tt.push_back(s);
            s[it.second]='.';
        }
        ans.push_back(tt);
    }

    return ans;
    }
};
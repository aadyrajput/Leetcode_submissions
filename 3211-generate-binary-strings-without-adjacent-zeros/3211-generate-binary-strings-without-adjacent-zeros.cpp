class Solution {
public:
    void fun(int i,int last,string temp,vector<string> &ans,int n){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        if(last!=0) {
            fun(i+1,1,temp+"1",ans,n);
            fun(i+1,0,temp+"0",ans,n);
        }
        else{
            fun(i+1,1,temp+"1",ans,n);
        }
    }

    vector<string> validStrings(int n) {
        string temp;
        vector<string> ans;
        fun(0,-1,temp,ans,n);
        return ans;
    }
};
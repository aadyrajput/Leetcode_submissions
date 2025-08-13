class Solution {
private:
bool isPalindrome(string ss){
    int n1=ss.size();
    if(n1==1)return true;
    for(int i=0;i<n1/2; i++){
        if(ss[i]!=ss[n1-1-i]) return false;
    }
    return true;
}

void fun(int i,string s,vector<string>temp,vector<vector<string>>&v){
    if(i==s.size()){
        v.push_back(temp);
        return;
    }
    int n=s.size();
    string x;
    for(int j=i; j<n; j++){
        x.push_back(s[j]);
        if(isPalindrome(x)){
            temp.push_back(x);
            fun(j+1,s,temp,v);
            temp.pop_back();
        }
    }
}

public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        fun(0,s,temp,ans);
        return ans;
    }
};
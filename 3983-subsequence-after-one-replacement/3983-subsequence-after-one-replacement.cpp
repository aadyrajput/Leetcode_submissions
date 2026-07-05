class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
       int m=s.size();
       int n=t.size();
       if(m>n)return false;
      vector<int> pre(m,1e9),suff(n,-1e9);
    
    int j=0;
    for(int i=0;i<m;i++){
        while(j<n && s[i]!=t[j])j++;
        if(j==n)break;
        pre[i]=j; j++;
    }
    j=n-1;
    for(int i=m-1;i>=0;i--){
        while(j>=0 && s[i]!=t[j])j--;
        if(j<0)break;
        suff[i]=j; j--;
    }

    for(int i=0;i<m; i++){
        int le=-1, ri=n;
        if(i>0) le=pre[i-1];
        if(i<m-1)ri=suff[i+1];
        if(le+1<ri)return true;
    }
    return false;
    }
};
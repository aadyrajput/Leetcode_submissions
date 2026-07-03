class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
      int n=derived.size();
      if(n==1){
        if(derived[0]==0)return true;
        return false;
      }
      vector<int> pre(n),suff(n);
      pre[0]=derived[0], suff[n-1]=derived[n-1];
      for(int i=1;i<n;i++)pre[i]=pre[i-1]^derived[i];
      for(int i=n-2;i>=0;i--)suff[i]=suff[i+1]^derived[i];
      
      for(int i=0;i<n-1;i++){
        if(pre[i]!=suff[i+1])return false;
      }
      return true;
    }
};
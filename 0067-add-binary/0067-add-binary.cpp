class Solution {
public:
    string addBinary(string a, string b) {
       int z1=a.size(); int z2=b.size();
       if(z1<z2){
        reverse(a.begin(),a.end());
        int z=z2-z1;
        while(z--)a+='0';
        reverse(a.begin(),a.end());
       }
       else if(z1>z2){
         reverse(b.begin(),b.end());
        int z=z1-z2;
        while(z--)b+='0';
        reverse(b.begin(),b.end());
       }
       int z=a.size(); int car=0; string ans="";
       for(int i=z-1;i>=0; i--){
          int ct=0;
          if(a[i]=='1') ct++;
          if(b[i]=='1') ct++;
          if(car==1) ct++;
          if(ct==0){ans+='0'; continue;}
          if(ct==1){ans+='1'; car=0;continue;}
          if(ct==2){ans+='0'; car=1; continue;}
          if(ct==3){ans+='1'; car=1; continue;}
       }
       if(car==1)ans+='1';
       reverse(ans.begin(),ans.end());

    return ans;
    }
};
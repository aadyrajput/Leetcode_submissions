class Solution {
public:
    int numSteps(string s) {
        int ans=0;
    while(s.size()!=1){
        ans++;
        if(s.back()=='0')s.pop_back();
        else{
            reverse(s.begin(),s.end());
            int car=1;
            string ss="0";
            for(int i=1;i<s.size(); i++){
                if(s[i]=='1'){
                    if(car==1)ss+='0';
                    else{ss+=s[i]; car=0;}
                }
                else{
                    if(car==1){ss+='1'; car=0;}
                    else ss+='0';
                }
            }
            if(car==1)ss+='1';
            reverse(ss.begin(),ss.end());
            s=ss;
        }
    }
        
    return ans;
    }
};
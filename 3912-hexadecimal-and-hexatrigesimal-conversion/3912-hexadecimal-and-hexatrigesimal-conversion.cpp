class Solution {
public:
    string concatHex36(int n) {
        int nsq=n*n;
        string ans1="";
        while(nsq>0){
            int x=nsq%16;
            if(x<10) ans1+=to_string(x);
            else ans1.push_back(x-10+'A');
         nsq/=16;
        }
        string ans2="";
        nsq=n*n*n;
         while(nsq>0){
            int x=nsq%36;
            if(x<10) ans2+=to_string(x);
            else ans2.push_back(x-10+'A');
        nsq/=36;
        }
        reverse(ans1.begin(),ans1.end());
         reverse(ans2.begin(),ans2.end());
    return ans1+ans2;
    }
};
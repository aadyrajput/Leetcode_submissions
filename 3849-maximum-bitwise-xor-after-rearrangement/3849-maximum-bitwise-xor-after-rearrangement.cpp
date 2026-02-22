class Solution {
public:
    string maximumXor(string s, string t) {
        int ct0=0; int ct1=0;
        for(auto it:t){
            if(it=='0')ct0++;
            else ct1++;
        }
        string tt="";
        for(int i=0;i<s.size(); i++){
            if(s[i]=='0'){
                if(ct1!=0){tt+='1';ct1--;}
                else {tt+='0'; ct0--;}
            }
            else{
                if(ct0!=0){tt+='0'; ct0--;}
                else{tt+='1'; ct1--;}
            }
        }
        string res="";
        for(int i=0;i<s.size(); i++){
            int ct0=0;
            if(s[i]=='0')ct0++;
            if(tt[i]=='0')ct0++;

            if(ct0==0 || ct0==2)res+='0';
            else res+='1';
        }
        return res;


    }
};
class Solution {
public:
    bool isValid(string word) {
        bool ok=false;
        bool vow=false;
        bool con=false;
        bool digit=false;
        string s=word;
        for(int i=0; i<word.size(); i++){
            if((s[i]>='a' && s[i]<='z')){
                    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                        vow=true;
                    }
                    else con=true;
            }
            else if((s[i]>='A' && s[i]<='Z')){
                    if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                        vow=true;
                    }
                    else con=true;
            }
            else if(s[i]>='0' && s[i]<='9'){
                continue;
            }
            else{
                ok=true; break;
            }
        }        
        
        if(ok)return false;
        if(vow && con && word.size()>=3) return true;
        return false;
        
    }
};
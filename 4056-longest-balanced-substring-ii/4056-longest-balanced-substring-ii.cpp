class Solution {
private:
int fun1(string s,char x){
   int ct=0; int res=0;
   for(int i=0;i<s.size(); i++){
    if(s[i]==x)ct++;
    else{res=max(res,ct); ct=0;}
   }
   res=max(res,ct);
return res;
}

int fun2(string s,char a,char b,char c){
    int res=0;
    map<int,int> m;
    int cta=0, ctb=0;
    m[0]=-1;
    for(int i=0;i<s.size(); i++){
        if(s[i]==a)cta++;
        else if(s[i]==b)ctb++;
        else{
            cta=0; ctb=0; m.clear();
        }
        int z=cta-ctb;
        if(m.find(z)!=m.end()){
            res=max(res,i-m[z]);
        }
        else m[z]=i;
    }
    return res;
}

int fun3(string s){
    int res=0;
    int cta=0,ctb=0,ctc=0;
    map<pair<int,int>,int> m;
    m[{0,0}]=-1;
    for(int i=0;i<s.size(); i++){
        if(s[i]=='a')cta++;
        else if(s[i]=='b')ctb++;
        else ctc++;
        pair<int,int> p={cta-ctc,ctb-ctc};
        if(m.find(p)!=m.end()){
            res=max(res,i-m[p]);
        }
        else m[p]=i;
    }
    return res;
}


public:
    int longestBalanced(string s) {
        int ans=1;
        ans=max(ans,fun1(s,'a'));
        ans=max(ans,fun1(s,'b'));
        ans=max(ans,fun1(s,'c'));

        ans=max(ans,fun2(s,'a','b','c'));
        ans=max(ans,fun2(s,'a','c','b'));
        ans=max(ans,fun2(s,'c','b','a'));

        ans=max(ans,fun3(s));

        return ans;
    }
};
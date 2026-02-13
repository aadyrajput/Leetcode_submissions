class Solution {
public:
    void fun(char a,string &s,int &ans){
        int ct=0;
        for(int i=0;i<s.size(); i++){
            if(s[i]==a)ct++;
            else{
                ans=max(ans,ct);
                ct=0;
            }
        }
        ans=max(ans,ct);
    }
    void fun2(char a,char b,string &s,int &ans){
        map<int,int> m;
        int cta=0, ctb=0; 
        m[0]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==a)cta++;
            else if(s[i]==b)ctb++;
            else{cta=0; ctb=0; m.clear(); }
            if(m.find(cta-ctb)!=m.end())ans=max(ans,i-m[cta-ctb]);
            else m[cta-ctb]=i;
        }
    }
    int longestBalanced(string s){  
       int n=s.size();
       int ans=1;
    // for substring with 1 character
    fun('a',s,ans);
    fun('b',s,ans);
    fun('c',s,ans);

    // for substring with 2 char
    fun2('a','b',s,ans);
    fun2('a','c',s,ans);
    fun2('b','c',s,ans);
       
       map<pair<int,int>,int> m;
       int cta=0,ctb=0,ctc=0; m[{0,0}]=-1;
       for(int i=0;i<n;i++){
          if(s[i]=='a')cta++;
          else if(s[i]=='b')ctb++;
          else ctc++;
          if(ctb==cta && ctb==ctc)ans=max(ans,i+1);
          if(m.find({ctb-cta,ctc-cta})!=m.end()){
                ans=max(ans,i-m[{ctb-cta,ctc-cta}]);
          }
          else m[{ctb-cta,ctc-cta}]=i;
       }


        return ans;
    }
};
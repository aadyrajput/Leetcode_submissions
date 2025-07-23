class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x>=y){
         stack<char> st; int ab=0;
         for(int i=0;i<s.size(); i++){
            if(s[i]=='b'){
                if(!st.empty() && st.top()=='a'){
                    st.pop(); ab++;
                }
                else st.push('b');
            }
            else st.push(s[i]);
         }
         
         int ans=ab*x;
         int ba=0; string ss; 
          while(!st.empty()) {ss.push_back(st.top()); st.pop();}
          reverse(ss.begin(),ss.end());
          stack<char> st2; 
         for(int i=0;i<ss.size(); i++){
            if(ss[i]=='a'){
                if(!st2.empty() && st2.top()=='b'){
                    st2.pop(); ba++;
                }
                else st2.push('a');
            }
            else st2.push(ss[i]);
         }
         ans+=(ba*y);
         return ans;
        }



        stack<char> st; int ba=0;
         for(int i=0;i<s.size(); i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='b'){
                    st.pop(); ba++;
                }
                else st.push('a');
            }
            else st.push(s[i]);
         }
         int ans=ba*y;
         int ab=0; string ss;
         while(!st.empty()) {ss.push_back(st.top()); st.pop();}
         reverse(ss.begin(),ss.end());
          stack<char> st2; 
         for(int i=0;i<ss.size(); i++){
            if(ss[i]=='b'){
                if(!st2.empty() && st2.top()=='a'){
                    st2.pop(); ab++;
                }
                else st2.push('b');
            }
            else st2.push(ss[i]);
         }
         ans+=(ab*x);
         return ans;




        

    }
};
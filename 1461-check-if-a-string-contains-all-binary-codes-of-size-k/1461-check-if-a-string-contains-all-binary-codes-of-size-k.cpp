class Solution {
public:
    bool hasAllCodes(string s, int k) {
      set<string> st;
      int n=s.size();
      if(k>n)return false;
      int no=1<<k;

    string temp="";
      for(int i=0;i<k;i++){
        temp+=s[i];
      }
      st.insert(temp);
      for(int i=k;i<n;i++){
        temp.erase(0,1);
        temp+=s[i];
        st.insert(temp);
      }
      int z=st.size();
      if(z==no)return true;
      return false;
    }
};
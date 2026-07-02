class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int> st;
        int z=0; int ptr=0;
        for(int i=0;i<s.size();i++){
            z=z*2;
            if(s[i]=='1')z++;
            if(i<k-1)continue;
            else if(i==k-1)st.insert(z);
            else{
                if(s[ptr]=='1')z-=(1<<k);
                ptr++;
                st.insert(z);
            }
        }    
        int zz=1<<k;
        if(st.size()==zz)return true;
        return false;
    }
};
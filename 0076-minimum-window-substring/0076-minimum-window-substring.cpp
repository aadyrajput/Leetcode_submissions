class Solution {
public:
    bool check(map<char,int> &mt, map<char,int> &ms){
        if(ms.size()<mt.size())return false;
        for(auto it:mt){
            if(ms.find(it.first)==ms.end())return false;
            if(it.second>ms[it.first])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> mt;
        for(auto it:t)mt[it]++;
        map<char,int> ms;

        int ans=INT_MAX; int ind=-1;
        int ptr=0;
        for(int i=0;i<s.size(); i++){
            ms[s[i]]++;
            if(!check(mt,ms))continue;
            int z=i-ptr+1;
            if(z<ans){
                ans=z; ind=i;
            }
            while(check(mt,ms)){
                ms[s[ptr]]--;
                if(ms[s[ptr]]==0)ms.erase(s[ptr]);
                if(i-ptr+1<ans){
                    ans=i-ptr+1; ind=i;
                }
                ptr++;
            }
        }

        if(ans==INT_MAX || s.size()<t.size()) return "";
        if(s==t)return s;
        
        string res="";
        for(int i=ind+1-ans; i<=ind; i++){
            res+=s[i];
        }
    return res;
    }
};
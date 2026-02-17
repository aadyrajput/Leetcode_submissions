class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        vector<vector<string>> hr(11),min(11);
        for(int i=0;i<=11; i++){
            int z=__builtin_popcount(i);
            string s=to_string(i);
            hr[z].push_back(s);
        }
        for(int i=0;i<=59; i++){
            int z=__builtin_popcount(i);
            string s="";
            if(i<=9)s+='0';
             s+=to_string(i);
            min[z].push_back(s);
        }

        for(int i=0; i<=turnedOn; i++){
            vector<string> hrr=hr[i];
            vector<string> minn=min[turnedOn-i];
            for(int j=0; j<hrr.size();j++){
                for(int k=0;k<minn.size(); k++){
                    string res=hrr[j];
                    res+=':';
                    res+=minn[k];
                    ans.push_back(res);
                }
            }
        }
        return ans;




    }
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(auto it:queries){
            for(auto itt:dictionary){
                string a=it, b=itt;
                int ct=0;
                for(int i=0;i<a.size();i++){
                    if(a[i]!=b[i])ct++;
                    if(ct>2) break;
                }
                if(ct<=2){ans.push_back(it); break;}
            }
        }
        return ans;
    }
};
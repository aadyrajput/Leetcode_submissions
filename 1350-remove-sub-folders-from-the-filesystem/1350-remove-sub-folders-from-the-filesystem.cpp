class Solution {
private:
static bool comp(string &a,string &b){
    return a.size()<b.size();
   }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        map<string,int> m;
        sort(folder.begin(),folder.end(),comp);
        for(auto it: folder){
            string a=it;
            string b="";
            bool flag=false;
            for(int i=0; i<a.size(); i++){
                b+=a[i];
                if(i==a.size()-1 || a[i+1]=='/'){
                if(m.count(b)!=0){flag=true; break;}}
            }
            if(flag) continue;
            else m[a]++;
        }
        vector<string> ans;
        for(auto it:m){
            while(it.second--){
            ans.push_back(it.first); }
        }
        return ans;
    }
};
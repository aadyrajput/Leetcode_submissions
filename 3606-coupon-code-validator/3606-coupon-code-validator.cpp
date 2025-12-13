class Solution {

bool code_valid(string &z){
   if(z.size()==0)return false;
   int xx=0;
   for(int i=0;i<z.size(); i++){
    if(z[i]>='A' && z[i]<='Z') xx=1;
    else if(z[i]>='a' && z[i]<='z')xx=1;
    else if(z[i]>='0' && z[i]<='9')xx=1;
    else if(z[i]=='_') xx=1;
    else return false; 
   }
    return true;
}

bool business_valid(string &z){
    if(z=="electronics" || z=="grocery" || z=="pharmacy" || z=="restaurant") return true;
    return false;
}

bool active_valid(bool z){
    return z;
}

bool static comp(pair<string,string> &a,pair<string,string> &b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive){
int n=code.size();
vector<int> valid;
vector<string> ans;
for(int i=0;i<n;i++){
    if(code_valid(code[i]) && business_valid(businessLine[i]) && active_valid(isActive[i])){
        valid.push_back(i);
    }
}
if(valid.size()==0)return ans;
vector<pair<string,string>> v;
for(auto it:valid){
    v.push_back({businessLine[it],code[it]});
}
sort(v.begin(),v.end(),comp);
for(auto it:v){
    ans.push_back(it.second);
}
return ans;
    
        
    }
};
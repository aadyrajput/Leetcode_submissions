class Solution {
public:
    string sortVowels(string s) {
    vector<char> v;
    for(auto it:s){
        if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u')v.push_back(it);
        if(it=='A' || it=='E' || it=='I' || it=='O' || it=='U')v.push_back(it);
    }
    sort(v.begin(),v.end());
        int ct=0;
      for(int i=0;i<s.size(); i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){s[i]=v[ct]; ct++;}
    }
    return s;
    }
};
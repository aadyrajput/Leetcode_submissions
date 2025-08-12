class Solution {
private:
void fun(int i,string temp,map<int,string> &m,string &digits,vector<string> &ans){
    if(i==digits.size()){
        ans.push_back(temp);
        return;}
    string sss=m[digits[i]-'0'];
    for(int j=0; j<sss.size(); j++){
        temp.push_back(sss[j]);
        fun(i+1,temp,m,digits,ans);
        temp.pop_back();
    }

}
public:
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
        if(digits=="")return ans;
            map<int,string> m;
            m[2]="abc"; m[3]="def"; m[4]="ghi";  m[5]="jkl"; m[6]="mno"; 
            m[7]="pqrs";  m[8]="tuv"; m[9]="wxyz";
        string temp;
        fun(0,temp,m,digits,ans);
        return ans;
    }
};
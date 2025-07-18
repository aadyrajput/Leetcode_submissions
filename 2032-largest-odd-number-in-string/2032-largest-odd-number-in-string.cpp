class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int x=-1;
        for(int i=0; i<num.size(); i++){
            int z=num[i]-'0';
            if(z%2!=0) x=max(x,i);
        }
        if(x==-1) return "";
        for(int i=0; i<=x; i++){
            ans.push_back(num[i]);
        }
        return ans;

    }
};
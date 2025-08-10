class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());

        for(int i=0;i<31; i++){
            string x=to_string(1<<i);
            sort(x.begin(),x.end());
            if(x==s)return true;
        }
        return false;

    }
};
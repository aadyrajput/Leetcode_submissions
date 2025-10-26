class Solution {
// private:
// void 

public:
    string maxSumOfSquares(int num, int sum) {
        int zz=num*9;
        if(sum>zz)return "";
        string ans="";
        for(int i=0; i<num; i++){
            if(sum==0){
                string z="0";
                ans+=z;
            }
            else if(sum>=9){
                string z="9";
                ans+=z; sum-=9;
            }
            else{
                string z=to_string(sum);
                ans+=z; sum=0;
            }
        }

    return ans;
    }
};
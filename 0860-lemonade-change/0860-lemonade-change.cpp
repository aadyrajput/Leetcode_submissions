class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ct5=0,ct10=0,ct20=0;
        for(auto it:bills){
            if(it==5)ct5++;
            else if(it==10){
                if(ct5==0)return false;
                ct5--; ct10++;
            }
            else{
                if(ct5>=1 && ct10>=1){ct5--; ct10--;}
                else if(ct5>=3){ct5=ct5-3;}
                else return false;
            }
        }
    return true;
    }
};
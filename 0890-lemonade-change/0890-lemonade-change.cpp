class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ct5=0; int ct10=0; 
        int n=bills.size();
        bool ans=true;
        for(int i=0;i<n; i++){
            if(bills[i]==5) ct5++;
            else if(bills[i]==10){
                if(ct5==0){ans=false; break;}
                ct5-=1; ct10++;
            }
            else{
                int a=ct5; int b=ct10;
                if(b>=1 && a>=1){
                    ct10--; ct5--;
                }
                else if(a>=3){
                    ct5-=3; 
                }
                else{
                    ans=false; break;
                }
            }
        }

        return ans;
    }
};
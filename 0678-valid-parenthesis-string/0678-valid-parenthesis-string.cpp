class Solution {
public:
    bool checkValidString(string s) {
         int mina=0;
         int maxa=0;
         for(auto it:s){
            if(it=='('){
                mina++; maxa++;
            }
            else if(it==')'){
                mina--; maxa--;
            }
            else{
                mina--; maxa++;
            }
            
            if(mina<0)mina=0;

            if(maxa<0)return false;      // edge case
         }
         if(mina==0)return true;
         return false;
    }
};
class Solution {
public:
    bool judgeCircle(string moves) {
      int ct1=0; int ct2=0;
      for(auto it:moves){
        if(it=='L') ct1++;
        else if(it=='R')ct1--;
        else if(it=='U')ct2++;
        else ct2--;
      }   
      if(ct1==0 && ct2==0)return true;
      return false;
    }
};
class Solution {
public:
    bool hasAlternatingBits(int n) {
      long long x= n^ (n>>1);
     long long zz= x&(x+1);
      if(zz==0)return true;
      return false;
    }
};
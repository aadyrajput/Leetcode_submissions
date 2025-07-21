class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ct=0;
        for(int i=0; i<=31; i++){
            int x= 1<<i;
            int y= start&x;
            int z=goal&x;
            if(z!=y) ct++;
        }
        return ct;
    }
};
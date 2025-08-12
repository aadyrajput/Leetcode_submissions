class Solution {
private:
 int solve(int a,int sec,int M){
    int ans=1;
    while(sec){
        if(sec&1) ans= (ans*a)%M;
        a= (a*a)%M;
        sec= sec>>1;
    }
    return ans;
 }
public:
    int superPow(int a, vector<int>& b) {
        a%=1337;
        int n=b.size();
        int m=1140;
        int sec=0;
        for(int i=0;i<b.size(); i++){
            sec=(sec*10+b[i])%m;
        }
        if(sec==0) sec=m;
        return solve(a,sec,1337);
    }
};
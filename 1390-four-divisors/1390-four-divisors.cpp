class Solution {
int fun(int x){
    if(x<=5)return 0;
    map<int,int>m; int xx=x;
  for(int i=2; i*i<=xx; i++){
    while(xx%i==0){
        m[i]++;
        xx=xx/i;
     if(m[i]>3)return 0;
    } 
    if(m.size()>2)return 0;
  }
  if(xx>1) m[xx]++;
 if(m.size()==1){
    int p=m.begin()->first;
    if(m.begin()->second!=3)return 0;
    return 1+p+ p*p + p*p*p;
 }
 int res=1;
 if(m.size()!=2)return 0;
 for(auto it:m){
    if(it.second!=1)return 0;
    res*=(it.first+1);
 }
return res;
}

public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        map<int,int>mm;
        for(auto it:nums){
            mm[it]++;
        }
        for(auto it:mm){
            int z=it.second*fun(it.first);
            sum+=z;
        }
    return sum;
    }
};
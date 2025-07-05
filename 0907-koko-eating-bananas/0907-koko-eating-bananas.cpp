class Solution {
private:
bool check(int mid,vector<int>&piles,int h){
    int ans=0;
    for(int i=0; i<piles.size(); i++){
        ans+=ceil((double)piles[i]/(double)mid);
        if(ans>h)return false;
    }
    return true;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        if(h==piles.size()){return piles[n-1];}
        int lo=1; int hi=piles[n-1];
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(check(mid,piles,h)) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};
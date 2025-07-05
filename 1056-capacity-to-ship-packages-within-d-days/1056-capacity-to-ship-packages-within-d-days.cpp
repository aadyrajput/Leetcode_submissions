class Solution {
private:
bool check(int mid,vector<int>& weights, int days){
    int ans=0; int ctdays=1;
    for(int i=0;i<weights.size(); i++){
        if(ans+weights[i]>mid){
            ctdays++; ans=weights[i];
        }
        else ans+=weights[i];
    }
    if(ctdays<=days) return true; 
    return false;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
     int n=weights.size();
     int sum=0;
     for(int i=0;i<weights.size(); i++)sum+=weights[i];
     int lo=*max_element(weights.begin(),weights.end()); int hi=sum;
     while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,weights,days)) hi=mid-1;
        else  lo=mid+1;
     }
        return lo;
    }
};
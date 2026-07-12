class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     int n=arr.size();
     if(n==0)return {};
     vector<int> ans(n,0);
     priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
     for(int i=0;i<n;i++){
        pq.push({arr[i],i});
     }
     int ct=1;
    int z=pq.top().first, ind=pq.top().second;
    ans[ind]=ct;

     while(!pq.empty()){
        int zz=pq.top().first, indd=pq.top().second;
        pq.pop();
        if(zz!=z){
            ct++; ans[indd]=ct;
            z=zz;
        }
        else ans[indd]=ct;
     }
    return ans;
    }
};
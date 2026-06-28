class Solution {
public:
    const int M=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<long long>  pq;
        for(int i=0;i<n;i++){
            long long sum=nums[i];
            pq.push(sum);
            while(pq.size()>right)pq.pop();
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                pq.push(sum);
            while(pq.size()>right)pq.pop();
            }
        }
        long long ans=0;
        while(pq.size()>=left){
            ans=(ans+pq.top())%M;
            pq.pop();
        }
        return ans;

    }
};
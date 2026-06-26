class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>> pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums)pq.push(it);
        kk=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>kk){
            pq.pop();
        }
    return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
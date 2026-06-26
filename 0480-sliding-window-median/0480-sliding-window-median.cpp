class Solution {
public:
    multiset<int> left,right;  //left-maxheap, right=minheap

    void balance(){
        while(left.size()>right.size()+1){
            auto it=--left.end();
            right.insert(*it);
            left.erase(it);
        }
        while(left.size()<right.size()){
            auto it=right.begin();
            left.insert(*it);
            right.erase(it);
        }
    }

    void add(long long z){
        if(left.empty() || z<=*(--left.end()))left.insert(z);
        else right.insert(z);
        balance();
    }
    void remove(long long z){
        if(left.find(z)!=left.end())left.erase(left.find(z));
        else right.erase(right.find(z));
        balance();
    }
    double median(){
        if(left.size()>right.size())return *(--left.end());
        return ((double) *(--left.end() )+ *(right.begin()))/2.0;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
            if(i>=k)remove(nums[i-k]);
            if(i>=k-1)ans.push_back(median());
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n,0);
        vector<int> temp;
        for(int i=0;i<n; i++){
            if(nums[i]>=0){
                temp.push_back(nums[i]);
                v[i]=1;
            }
        }
        int nn=temp.size();
        if(nn==0)return nums;
        k=k%nn;
        vector<int> temp2;
        for(int i=k; i<temp.size(); i++){
            temp2.push_back(temp[i]);
        }
        for(int i=0;i<k; i++){
            temp2.push_back(temp[i]);
        }
       // return temp2;
        int j=0;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                nums[i]=temp2[j]; j++;
            }
        }
        return nums;
         

    }
};
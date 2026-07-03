class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitset(32, -1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 31; j++) {
                if (nums[i] & (1ll << j)) {
                    bitset[j] = i;
                }
            }
            int temp = i;
            for (int k = 0; k <= 31; k++) {
                temp = max(temp, bitset[k]);
            }
            ans[i] = temp - i + 1;
        }
        return ans;
    }
};
class Solution {
private:
    long long NEG = -1e18; // ADDED: to handle invalid states safely

    // CHANGED SIGNATURE:
    // - removed confusing tra%2 logic
    // - replaced z with clear state:
    //   0 = free, 1 = holding long, 2 = holding short
    long long fun(int ind, int t, int state, int n, int k,
                  vector<int>& arr,
                  vector<vector<vector<long long>>>& dp) {

        // FIXED BASE CASE:
        // cannot end with open position
        if (ind == n || t == k)
            return (state == 0 ? 0 : NEG);

        if (dp[ind][t][state] != -1)
            return dp[ind][t][state];

        long long profit = NEG;

        // ===== FREE STATE =====
        if (state == 0) {
            profit = max({
                fun(ind + 1, t, 0, n, k, arr, dp),        // skip
                -arr[ind] + fun(ind + 1, t, 1, n, k, arr, dp), // buy (long)
                 arr[ind] + fun(ind + 1, t, 2, n, k, arr, dp)  // sell (short)
            });
        }

        // ===== HOLDING LONG =====
        else if (state == 1) {
            profit = max({
                fun(ind + 1, t, 1, n, k, arr, dp),        // hold
                arr[ind] + fun(ind + 1, t + 1, 0, n, k, arr, dp) // sell → transaction++
            });
        }

        // ===== HOLDING SHORT =====
        else { // state == 2
            profit = max({
                fun(ind + 1, t, 2, n, k, arr, dp),        // hold
                -arr[ind] + fun(ind + 1, t + 1, 0, n, k, arr, dp) // buy back → transaction++
            });
        }

        return dp[ind][t][state] = profit;
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        // FIXED DP SIZE:
        // dp[ind][transactions][state]
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, -1))
        );

        return fun(0, 0, 0, n, k, prices, dp); // start free
    }
};

class Solution {
public:

    int countLocalMaximums(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<array<int,3>> v;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] != 0)
                    v.push_back({matrix[i][j], i, j});
            }
        }

        sort(v.rbegin(), v.rend());

        int ans = 0;

        vector<array<int,3>> done;

        for(auto &cur : v) {

            int val = cur[0];
            int x = cur[1];
            int y = cur[2];

            bool ok = true;

            for(auto &p : done) {

                // only larger values matter
                if(p[0] <= val)
                    break;

                int a = abs(p[1] - x);
                int b = abs(p[2] - y);

                if(a == val && b == val)
                    continue;

                if(a <= val && b <= val) {
                    ok = false;
                    break;
                }
            }

            if(ok)
                ans++;

            done.push_back(cur);
        }

        return ans;
    }
};
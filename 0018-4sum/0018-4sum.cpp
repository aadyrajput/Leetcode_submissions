class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<long long>> s;
        map<long long, long long> m;

        for (auto it : nums) m[it]++;

        for (auto it : m) {
            for (auto itt : m) {
                for (auto ittt : m) {
                    long long a = it.first;
                    long long b = itt.first;
                    long long c = ittt.first;
                    long long d = 1LL * target - a - b - c;

                    if (m.count(d) == 0) continue;

                    if (a == b && a == c && a == d) {
                        if (m[a] < 4) continue;
                        vector<long long> t = {a, a, a, a};
                        s.insert(t);
                    }
                    else if (a == b && a == c && a != d) {
                        if (m[a] < 3) continue;
                        vector<long long> t = {a, a, a, d};
                        s.insert(t);
                    }
                    else if (a == b && a != c && a != d) {
                        if (m[a] < 2) continue;
                        if (c == d && m[c] < 2) continue;
                        vector<long long> t = {a, a, c, d};
                        s.insert(t);
                    }
                    else if (a < b && b < c && c < d) {
                        vector<long long> t = {a, b, c, d};
                        s.insert(t);
                    }
                }
            }
        }

        set<vector<long long>> s2;
        for (auto it : s) {
            vector<long long> v = it;
            sort(v.begin(), v.end());
            s2.insert(v);
        }

        vector<vector<int>> ans;
        for (auto it : s2) {
            vector<int> temp;
            for (auto x : it) temp.push_back((int)x);
            ans.push_back(temp);
        }
        return ans;
    }
};

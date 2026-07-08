class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for(char c : s) t += c, t += '#';

        int n = t.size(), c = 0, r = 0, mx = 0, id = 0;
        vector<int> p(n);

        for(int i = 0; i < n; i++) {
            if(i < r) p[i] = min(r - i, p[2 * c - i]);

            while(i - p[i] - 1 >= 0 &&
                  i + p[i] + 1 < n &&
                  t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;

            if(i + p[i] > r)
                c = i, r = i + p[i];

            if(p[i] > mx)
                mx = p[i], id = i;
        }

        return s.substr((id - mx) / 2, mx);
    }
};
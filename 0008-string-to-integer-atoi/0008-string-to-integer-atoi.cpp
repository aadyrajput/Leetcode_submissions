class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        bool started = false;
        long long ans = 0;
        int i = 0;

        while (i < s.size() && s[i] == ' ') i++; // Skip leading spaces

        // Check for optional sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Parse numeric characters
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow checks
            if (ans > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return (int)(sign * ans);
    }
};

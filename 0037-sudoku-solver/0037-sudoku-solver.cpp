#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& b) {
        solve(b);
    }
private:
    bool solve(vector<vector<char>>& b) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (b[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (valid(b, i, j, c)) {
                            b[i][j] = c;
                            if (solve(b)) return true;
                            b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(vector<vector<char>>& b, int r, int c, char v) {
        for (int i = 0; i < 9; ++i) {
            if (b[i][c] == v) return false;
            if (b[r][i] == v) return false;
            if (b[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == v) return false;
        }
        return true;
    }
};
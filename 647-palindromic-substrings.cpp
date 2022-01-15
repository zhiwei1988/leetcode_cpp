//
// Created by ZhiWei Tan on 12/22/21.
//

#include "playground.h"

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][j] 表示子串 s[i, j] 为回文子串
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    result++;
                }
            }
        }

        return result;
    }
};

int main() {
    string s = "aaa";
    auto result = Solution().countSubstrings(s);
    std::cout << "ans = " << result << std::endl;
    return 0;
}


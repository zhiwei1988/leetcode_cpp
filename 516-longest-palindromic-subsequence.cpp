//
// Created by ZhiWei Tan on 12/22/21.
//

#include "playgroud.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][i] 表示 s[i, j] 中能形成回文子序列的最多字符数
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};

int main() {
    string s = "bbbab";
    auto result = Solution().longestPalindromeSubseq(s);
    std::cout << "ans = " << result << std::endl;
    return 0;
}


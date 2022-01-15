//
// Created by ZhiWei Tan on 12/20/21.
//

#include "playground.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // dp[i][j] 表示 s[i...j] 是否为回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int end = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if ((j - i) > (end - start)) {
                        start = i;
                        end = j;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main() {
    string s = "cbbd";
    auto result = Solution().longestPalindrome(s);
    std::cout << "ans = " << result << std::endl;
    return 0;
}


//
// Created by ZhiWei Tan on 12/24/21.
//

#include "playground.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        getPalindromeSubstr(s, dp, n);
        vector<string> path {};
        backtrace(s, 0, n, dp, path);
        return m_result;
    }

    /**
     * 获取输入字符串的所有回文子串
     * @param s
     * @param dp
     * @param n
     */
    void getPalindromeSubstr(string s, vector<vector<bool>> &dp, int n)
    {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }
    }

    void backtrace(string s, int pos, int len, vector<vector<bool>> &dp, vector<string> &path)
    {
        if (pos == len) {
            m_result.push_back(path);
        }

        for (int i = pos; i < len; i++) {
            if (!dp[pos][i]) {
                continue;
            }

            string substr = s.substr(pos, i - pos + 1);
            path.push_back(substr);
            backtrace(s, i + 1, len, dp, path);
            path.pop_back();
        }
    }

    vector<vector<string>> m_result;
};

int main()
{
    string s = "aab";
    auto result = Solution().partition(s);
    return 0;
}


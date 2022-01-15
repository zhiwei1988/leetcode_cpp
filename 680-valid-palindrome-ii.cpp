//
// Created by ZhiWei Tan on 12/12/21.
//

#include "playground.h"

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            }

            // 当遇到两个字符不相等时，最多可以删除 1 个字符
            // 尝试删除其中的任意一个，看剩余的字符串是否时回文字符串
            if (IsPalindrome(s, i + 1, j) || IsPalindrome(s, i, j - 1)) {
                return true;
            } else {
                return false;
            }
        }

        return true;
    }

    bool IsPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main(void)
{
    string s = "abc";
    auto res = Solution().validPalindrome(s);
    cout << "res = " << res << endl;
    return 0;
}


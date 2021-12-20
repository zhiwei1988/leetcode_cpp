//
// Created by ZhiWei Tan on 12/12/21.
//

#include "playgroud.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string strX(to_string(x));
        string rStr = strX;
        reverse(rStr.begin(), rStr.end());

        return rStr == strX;
    }
};


int main(void)
{
    int num = 121;
    auto res = Solution().isPalindrome(num);
    cout << "res = " << res << endl;
    return 0;
}
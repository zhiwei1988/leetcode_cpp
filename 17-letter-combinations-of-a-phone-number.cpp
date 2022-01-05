//
// Created by zhiwei on 1/5/2022.
//

#include "playgroud.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return result;
        }

        string path;
        backtrace(path, 0, digits);
        return result;
    }
    
    void backtrace(string path, int index, string digits)
    {
        if (path.length() == digits.length()) {
            result.push_back(path);
            return;
        }
        
        auto chars = charOnDigit[digits[index] - '0'];
        for (int i = 0; i < chars.size(); i++) {
            string tmp = path + chars[i];
            backtrace(tmp, index + 1, digits);
        }
    }
    
private:
    vector<vector<string>> charOnDigit = {
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
    };

    vector<string> result;
};

int main()
{
    string digits = "23";
    auto ret = Solution().letterCombinations(digits);
    return 0;
}


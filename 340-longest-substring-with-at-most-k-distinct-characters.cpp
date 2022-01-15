//
// Created by ZhiWei Tan on 1/1/22.
//

#include "playground.h"

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        vector<int> freq(128, 0);
        int diff = 0;
        int maxLen = 0;
        while (right < s.length()) {
            char c = s[right];
            if (freq[c] == 0) {
                diff++;
            }

            freq[c]++;

            while (diff > k) {
                char c1 = s[left];
                freq[c1]--;
                if (freq[c1] == 0) {
                    diff--;
                }
                left++;
            }

            int len = right - left + 1;
            maxLen = max(maxLen, len);
            right++;
        }

        return maxLen;
    }
};

int main()
{
    string s = "eceba";
    int k = 2;
    auto ret = Solution().lengthOfLongestSubstringKDistinct(s, k);
    cout << "ans = " << ret << endl;
    return 0;
}


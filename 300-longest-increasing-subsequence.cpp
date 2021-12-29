//
// Created by ZhiWei Tan on 12/29/21.
//

#include "playgroud.h"

class Solution {
public:
    /**
     * 求最长递增子序列（Longest Increasing Subsequence）的长度
     * @param nums
     * @return
     */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (!dp.size() || nums[i] > dp.back()) {
                // nums[i] 满足子序列递增的属性，直接加入子序列
                dp.push_back(nums[i]);
            } else {
                // nums[i] 不满足递增属性，从已有的子序列中找出第一个大于等于 nums[i] 的数
                // 用 nums[i] 替换它，因为 nums[i] 小于等于被替换的值，所以剩余的数能形成
                // 子序列长度肯定大于等于被替换之前的
                *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
            }
        }

        return dp.size();
    }
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    auto ret = Solution().lengthOfLIS(nums);
    return ret;
}


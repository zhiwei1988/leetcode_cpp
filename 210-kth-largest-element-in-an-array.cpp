//
// Created by ZhiWei Tan on 1/8/22.
//

#include "playgroud.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main()
{
    int k = 2;
    vector<int> nums = {3,2,1,5,6,4};
    auto ret = Solution().findKthLargest(nums, k);
    return 0;
}


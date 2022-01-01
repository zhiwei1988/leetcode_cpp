//
// Created by ZhiWei Tan on 1/1/22.
//

#include "playgroud.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hashMap.count(diff)) {
                return {i, hashMap[diff]};
            }
            hashMap[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto ret = Solution().twoSum(nums, target);
    cout << "ans = " << integerVectorToString(ret, ret.size());
    return 0;
}


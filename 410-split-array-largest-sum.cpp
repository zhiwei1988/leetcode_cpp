//
// Created by zhiwei on 12/28/2021.
//

#include "playground.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sumValue = accumulate(nums.begin(), nums.end(), 0);
        int maxValue = *max_element(nums.begin(), nums.end());
        return binarySearch(nums, m, maxValue, sumValue);
    }

    int binarySearch(vector<int>& nums, int m, int left, int right)
    {
        int minValue = left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (IsValid(nums, m,mid)) {
                if (mid == minValue || !IsValid(nums, m, mid - 1)) {
                    return mid;
                }

                right = mid - 1;
            } else {
                // 可以切的份数大于目标值，说明切的间隔太小了，需要调大
                left = mid + 1;
            }
        }

        return -1;
    }

    bool IsValid(vector<int>& nums, int m, int minValue)
    {
        int cnt = 1;
        int curSum = 0;
        for (auto num : nums) {
            curSum += num;
            if (curSum > minValue) {
                curSum = num;
                cnt++;
                if (cnt > m) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<int> nums = {7,2,5,10,8};
    int m = 2;
    auto ret = Solution().splitArray(nums, m);
    cout << "ret = " << ret << endl;
    return 0;
}


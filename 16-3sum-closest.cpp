//
// Created by ZhiWei Tan on 1/1/22.
//

#include "playgroud.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int b = nums[left];
                int c = nums[right];
                int sum = a + b + c;
                int diff = fabs(sum - target);
                if (diff < mindiff) {
                    mindiff = diff;
                    res = sum;
                } else if (diff == 0) {
                    return sum;
                }

                if (sum <= target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    auto ret = Solution().threeSumClosest(nums, target);
    cout << "ans = " << ret << endl;
    return 0;
}


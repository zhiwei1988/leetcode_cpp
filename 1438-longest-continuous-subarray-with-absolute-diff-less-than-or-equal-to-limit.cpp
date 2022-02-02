//
// Created by ZhiWei Tan on 2/2/22.
//

#include "playground.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLen = INT_MIN;
        deque<int> maxQ; // 单调递减队列
        deque<int> minQ; // 单调递增队列
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (!maxQ.empty() && nums[i] >= nums[maxQ.back()]) {
                maxQ.pop_back(); // 保证单调属性
            }

            while (!minQ.empty() && nums[i] <= nums[minQ.back()]) {
                minQ.pop_back(); // 保证单调属性
            }

            maxQ.push_back(i);
            minQ.push_back(i);

            while (fabs(nums[maxQ.front()] - nums[minQ.front()]) > limit) {
                if (minQ.front() == left) {
                    minQ.pop_front();
                }

                if (maxQ.front() == left) {
                    maxQ.pop_front();
                }

                left++;
            }

            maxLen = max(maxLen, i-left+1);
        }

        return maxLen;
    }
};

int main()
{
    vector<int> nums = {10,1,2,4,7,2};
    auto ret = Solution().longestSubarray(nums, 5);
    return 0;
}


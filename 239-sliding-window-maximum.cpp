//
// Created by ZhiWei Tan on 2/1/22.
//

#include "playground.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // 单调队列
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back(); // 删除队列中比新加入元素小的成员
            }

            q.push_back(i);
        }

        ans.push_back(nums[q.front()]); // 队列头部的元素即当前窗口下的最大值
        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && (q.front() <= i-k)) {
                q.pop_front(); // 该最大值对应的元素已经不在窗口中
            }

            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto ret = Solution().maxSlidingWindow(nums, k);
    return 0;
}


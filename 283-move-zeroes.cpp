//
// Created by ZhiWei Tan on 1/1/22.
//

#include "playgroud.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 通过快慢指针移除所有值为 0 的元素
        int pos = removeElement(nums, 0);
        // 在剩下的位置补上 0
        for (; pos < nums.size(); pos++) {
            nums[pos] = 0;
        }
    }
private:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0;
        int slow = 0;
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};


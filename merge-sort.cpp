//
// Created by ZhiWei Tan on 1/9/22.
//

#include "playground.h"

class Solution {
public:
    vector<int> mergeSort(vector<int> nums)
    {
        return divide(nums, 0, nums.size() - 1);
    }

    vector<int> divide(vector<int> nums, int left, int right)
    {
        if (left >= right) {
            return vector<int> {nums[left]};
        }

        int mid = left + (right - left) / 2;

        auto leftSide = divide(nums, left, mid);
        auto rightSide = divide(nums, mid + 1, right);
        return merge(leftSide, rightSide);
    }

    vector<int> merge(vector<int> &leftSide, vector<int> &rightSide)
    {
        vector<int> result(leftSide.size() + rightSide.size());
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < leftSide.size() && j < rightSide.size()) {
            if (leftSide[i] <= rightSide[j]) {
                result[k++] = leftSide[i++];
            } else {
                result[k++] = rightSide[j++];
            }
        }

        while (i < leftSide.size()) {
            result[k++] = leftSide[i++];
        }

        while (j < rightSide.size()) {
            result[k++] = rightSide[j++];
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {5,4,3,2,1};
    auto ret = Solution().mergeSort(nums);
    return 0;
}



//
// Created by zhiwei on 1/6/2022.
//

#include "playgroud.h"

int Partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[right]; // 每次取最右边的值为锚点
    int wall = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[wall]);
            wall++;
        }
    }

    swap(nums[wall], nums[right]);
    return wall;
}

void Helper(vector<int> &nums, int left, int right)
{
    if (left >= right) {
        return;
    }

    int pivot = Partition(nums, left, right);
    Helper(nums, left, pivot - 1);
    Helper(nums, pivot + 1, right);
}

void QuickSort(vector<int> &nums)
{
    Helper(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {3, 2, 1, 4};
    QuickSort(nums);
    return 0;
}



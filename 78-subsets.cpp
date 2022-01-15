//
// Created by zhiwei on 1/5/2022.
//

#include "playground.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        getSubset(nums, ans, 0, subset);
        return ans;
    }

private:
    void getSubset(vector<int>& nums, vector<vector<int>> &ans, int s, vector<int> &subset) {
        ans.push_back(subset);
        for (int i = s; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            getSubset(nums, ans, i+1, subset);
            subset.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    auto ret = Solution().subsets(nums);
    return 0;
}


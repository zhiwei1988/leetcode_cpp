//
// Created by zhiwei on 1/5/2022.
//

#include "playgroud.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        std::sort(nums.begin(), nums.end());
        getSubset(nums, ans, 0, subset);
        return ans;
    }
private:
    void getSubset(vector<int>& nums, vector<vector<int>> &ans, int s, vector<int> &subset) {
        ans.push_back(subset);
        for (int i = s; i < nums.size(); i++) {
            if (i > s && nums[i-1] == nums[i]) continue;
            subset.push_back(nums[i]);
            getSubset(nums, ans, i+1, subset);
            subset.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {1,2,2};
    auto ret = Solution().subsetsWithDup(nums);
    return 0;
}


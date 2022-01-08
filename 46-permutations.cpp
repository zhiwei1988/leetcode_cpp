//
// Created by zhiwei on 1/5/2022.
//

#include "playgroud.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> used;
        for (auto m : nums) {
            used[m] = false;
        }

        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, cur, used, ans);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& cur, unordered_map<int, bool>& used, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (auto m : nums) {
            if (used[m]) continue;
            cur.push_back(m);
            used[m] = true;
            dfs(nums, cur, used, ans);
            used[m] = false;
            cur.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    auto ret = Solution().permute(nums);
    return 0;
}


//
// Created by ZhiWei Tan on 12/21/21.
//

#include "playgroud.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 根据起点进行升序排序
        std::sort(begin(intervals), end(intervals), [] (const auto &left, const auto &right) -> bool {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }

            return left[0] < right[0];
        });

        int left = intervals[0][0];
        int right = intervals[0][1];

        vector<vector<int>> res;

        for (int i = 1; i < intervals.size(); i++) {
            if (right < intervals[i][0]) {
                // 新区间的起点大于当前区间的重点，则讲当前区间放入结果中
                // 更新当前区间的起点和终点
                res.push_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            } else if (right < intervals[i][1]) {
                // 新区间的起点小于当前区间的终点
                // 且新区间的终点大于当前区间的终点
                // 合并两个区间更新当前区间终点
                right = intervals[i][1];
            }

            // 合并区间
        }

        res.push_back(vector<int>{left, right});

        return res;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto result = Solution().merge(intervals);
    return 0;
}


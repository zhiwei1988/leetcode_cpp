//
// Created by zhiwei on 1/10/2022.
//

#include "playgroud.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> diffs;

        for (auto &trip : trips) {
            int s = trip[1];
            int e = trip[2];
            int diff = trip[0];
            diffs[s] += diff;
            diffs[e] -= diff;
        }

        int passengers = 0;
        for (auto &diff : diffs) {
            passengers += diff.second;
            if (passengers > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    auto ret = Solution().carPooling(trips, capacity);
    return 0;
}



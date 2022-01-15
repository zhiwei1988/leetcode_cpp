//
// Created by ZhiWei Tan on 1/2/22.
//

#include "playground.h"

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        auto maxDepth = getMaxDepth(nestedList);
        return dfs(nestedList, 1, maxDepth);
    }

    int getMaxDepth(vector<NestedInteger>& nestedList)
    {
        int maxDepth = 1;
        for (auto &item : nestedList) {
            if (!item.isInteger()) {
                maxDepth = max(maxDepth, 1 + getMaxDepth(item.getList()));
            }
        }

        return maxDepth;
    }

    int dfs(vector<NestedInteger>& nestedList, int level, int maxDepth) {
        int res = 0;
        for (auto &item : nestedList) {
            if (item.isInteger()) {
                res += item.getInteger() * (maxDepth - level + 1);
            } else {
                res += dfs(item.getList(), level + 1, maxDepth);
            }
        }

        return res;
    }
};
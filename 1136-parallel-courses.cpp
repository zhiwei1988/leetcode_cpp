//
// Created by ZhiWei Tan on 1/8/22.
//

#include "playgroud.h"

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> res;
        vector<int> inDegree(n + 1, 0); // 入度，依赖其他课程数
        vector<vector<int>> adj(n + 1, vector<int>{}); // 邻接表，被其他课程依赖

        // 构建邻接表、统计每个结点的入度
        for (int i = 0; i < relations.size(); i++) {
            int course = relations[i][1];
            int preCourse = relations[i][0];
            inDegree[course]++;
            adj[preCourse].push_back(course);
        }

        queue<int> courseQueue;

        size_t induSize = inDegree.size();
        for (int i = 1; i < induSize; i++) {
            if (inDegree[i] == 0) {
                // 入度为 0 的所有顶点在拓扑排序的结果中位于其它顶点的前面
                courseQueue.push(i);
            }
        }

        int courseNum = 0;
        while (!courseQueue.empty()) {
            size_t queueSize = courseQueue.size();
            for (int i = 0; i < queueSize; i++) {
                int course = courseQueue.front();
                res.push_back(course);
                courseQueue.pop();
                for (auto m : adj[course]) {
                    // 删除一条边，等价于被指向结点的入度减 1
                    inDegree[m]--;
                    if (inDegree[m] == 0) {
                        // 如果入度减 1 以后为 0，该结点就是接下来要遍历到的结点
                        courseQueue.push(m);
                    }
                }
            }
            courseNum++;
        }

        if (res.size() == n) {
            return courseNum;
        }

        return -1;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> relations = {{1,2},{2,3},{3,1}};
    auto ret = Solution().minimumSemesters(n, relations);
    return 0;
}
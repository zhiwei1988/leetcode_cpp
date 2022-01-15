//
// Created by zhiwei on 1/12/2022.
//

#include "playground.h"

class Solution { // Dijkstra 解法
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<TimeInfo>> adjs(n+1);
        // 构建邻接表
        for (int i = 0; i < times.size(); i++) {
            int s = times[i][0];
            int e = times[i][1];
            int time = times[i][2];
            adjs[s].push_back(TimeInfo(e, time));
        }
        // timeCost[i] 表示从节点 k 到节点 i 的最小耗时
        vector<int> timeCost(n+1, INT_MAX);
        timeCost[k] = 0;
        auto comp = [](const Vexter &left, const Vexter &right) {
            return left.time > right.time;
        };
        priority_queue<Vexter, vector<Vexter>, decltype(comp)> pq(comp);
        pq.emplace(k, 0);
        while (!pq.empty()) {
            auto vexter = pq.top();
            pq.pop();

            // 优先队列中可能存在多个 id == vexter.id 的 item
            if (vexter.time > timeCost[vexter.id]) {
                continue;
            }

            // 走到这里肯定满足 timeCost[vexter.id] == vexter.time;
            for (auto &adj : adjs[vexter.id]) {
                int d = vexter.time + adj.cost;
                if (d < timeCost[adj.dst]) {
                    timeCost[adj.dst] = d;
                    pq.emplace(adj.dst, d);
                }
            }
        }

        int maxCost = INT_MIN;
        for (int i = 1; i <= n; i++) {
            maxCost = max(maxCost, timeCost[i]);
        }

        return (maxCost == INT_MAX) ? -1 : maxCost;
    }
    struct TimeInfo {
        TimeInfo(int dst, int cost)
        {
            this->dst = dst;
            this->cost = cost;
        }
        int dst;
        int cost;
    };
    struct Vexter {
        Vexter(int id, int time)
        {
            this->id = id;
            this->time = time;
        }
        int id;
        int time; // 存储起始顶点到当前顶点的耗时
    };
};

class Solution2 { // Floyd 解法
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<long>> dist(n+1, vector<long>(n+1, INT_MAX));
        for (auto &time : times) {
            dist[time[0]][time[1]] = time[2];
        }

        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }

        for (int z = 1; z <= n; z++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][j] > dist[i][z] + dist[z][j]) {
                        dist[i][j] = dist[i][z] + dist[z][j];
                    }
                }
            }
        }

        long res = INT_MIN;
        for (int i = 1; i <= n; i++) {
            res = max(res, dist[k][i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    auto ret = Solution().networkDelayTime(times, n, k);
    return 0;
}


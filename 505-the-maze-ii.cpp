//
// Created by zhiwei on 1/12/2022.
//

#include "playground.h"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        auto m = maze.size();
        auto n = maze[0].size();
        // distances[x][y] 表示从起始顶点到当前顶点需要经过的最短距离
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        auto comp = [](const Vertex &l, const Vertex &r) {
            return l.distance > r.distance;
        };
        int sx = start[0];
        int sy = start[1];
        int dx = destination[0];
        int dy = destination[1];
        distances[sx][sy] = 0;
        priority_queue<Vertex, vector<Vertex>, decltype(comp)> q(comp);
        q.push(Vertex(sx, sy, distances[sx][sy]));
        while (!q.empty()) {
            auto pos = q.top(); // 返回队列中距离值最小的元素
            q.pop();

            if (pos.x == dx && pos.y == dy) {
                break;
            }

            if (pos.distance > distances[pos.x][pos.y]) {
                continue;
            }

            for (const auto &dir : directions) {
                int x = pos.x;
                int y = pos.y;

                int step = 0;
                do {
                    x += dir[0];
                    y += dir[1];
                    step++;
                } while (InMaze(maze, x, y) && maze[x][y] == 0);

                x -= dir[0];
                y -= dir[1];
                step--;

                if (pos.distance + step < distances[x][y]) {
                    distances[x][y] = pos.distance + step;
                    q.push(Vertex(x, y, distances[x][y]));
                }
            }
        }

        return distances[dx][dy] != INT_MAX ? distances[dx][dy] : -1;
    }
private:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    struct Vertex {
        Vertex(int x, int y, int dist) {
            this->x = x;
            this->y = y;
            this->distance = dist;
        }
        int x;
        int y;
        int distance; // 从起始点到当前顶点的距离（权值）
    };
    bool InMaze(vector<vector<int>>& maze, int x, int y) {
        if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size()) {
            return false;
        } else {
            return true;
        }
    }
};

int main()
{
    vector<vector<int>> maze = {{0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {1, 1, 0, 1, 1},
                                {0, 0, 0, 0, 0}};
    vector<int> start = {0, 4};
    vector<int> destination = {4, 4};

    auto ret = Solution().shortestDistance(maze, start, destination);
    return 0;
}


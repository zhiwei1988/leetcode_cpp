//
// Created by ZhiWei Tan on 1/2/22.
//

#include "playground.h"

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        visted.resize(maze.size());
        for (int i = 0; i < visted.size(); i++) {
            visted[i].resize(maze[0].size(), false);
        }

        queue<vector<int>> q;
        q.push(start);
        visted[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            for (const auto &dir : directions) {
                int x = pos[0];
                int y = pos[1];

                do {
                    x += dir[0];
                    y += dir[1];
                } while (InMaze(maze, x, y) && maze[x][y] == 0);

                x -= dir[0];
                y -= dir[1];

                if (x == destination[0] && y == destination[1]) {
                    return true;
                }

                if (InMaze(maze, x, y) && !visted[x][y] && maze[x][y] != 1) {
                    q.push({x, y});
                    visted[x][y] = true;
                }
            }
        }

        return false;
    }
private:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visted;
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
    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {4,4};

    auto ret = Solution().hasPath(maze, start, destination);
    cout << "ans = " << ret << endl;
    return 0;
}


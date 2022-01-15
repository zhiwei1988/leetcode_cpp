//
// Created by zhiwei on 1/13/2022.
//

#include "playground.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monotonicStack; // 单调递增栈（栈顶--->栈底）
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!monotonicStack.empty() && temperatures[i] > temperatures[monotonicStack.top()]) {
                result[monotonicStack.top()] = i - monotonicStack.top();
                monotonicStack.pop();
            }

            monotonicStack.push(i); // 温度比栈顶小，直接入栈
        }

        return result;
    }
};

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto ret = Solution().dailyTemperatures(temperatures);
    return 0;
}



#include "playground.h"

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        for (int i = 0; i < n; i++) {
            auto stick = matchsticks[i];
            stickMap[stick]++;
        }

        if (stickMap.size() == 1) {
            auto it = stickMap.begin();
            if (it->second % 4 == 0) {
                return true;
            }
        }
        sq.resize(4);
        return backtrace(matchsticks, 0);
    }

private:
    bool backtrace(vector<int>& matchsticks, int s)
    {
        if (s == matchsticks.size()) {
            return IsSquare();
        }

        for (int i = s; i < matchsticks.size(); i++) {
            for (int j = 0; j < 4; j++) {
                sq[j] += matchsticks[i];
                if (backtrace(matchsticks, i+1)) {
                    return true;
                }
                sq[j] -= matchsticks[i];
            }
        }

        return false;
    }

    bool IsSquare()
    {
        for (int i = 0; i < sq.size(); i++) {
            if (i != 0 && sq[i] != sq[i-1]) {
                return false;
            }
        }

        return true;
    }

    vector<int> sq;
    map<int, int> stickMap;
};

int main() {
    vector<int> matchsticks = {3,3,3,3,4};
    auto result = Solution().makesquare(matchsticks);
//    std::cout << "ans = " << result << std::endl;
    return 0;
}

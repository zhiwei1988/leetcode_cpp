//
// Created by ZhiWei Tan on 11/7/22.
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!isBadVersion(mid)) {
                left = mid + 1;
            } else {
                if (mid == 0 || !isBadVersion(mid - 1)) {
                    return mid;
                }

                right = mid - 1;
            }
        }

        return -1;
    }
};

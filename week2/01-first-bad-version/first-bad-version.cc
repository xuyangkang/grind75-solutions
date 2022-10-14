// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) {
            return 1;
        }
        int l = 1;
        int r = n;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
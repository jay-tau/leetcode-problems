class Solution {
public:
    int mySqrt(int x) {
        long long int l = 0, r = INT_MAX;
        bool flag = true;
        while (l < r) {
            long long mid = (l + r) / 2;
            if ((mid*mid) <= x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return (l-1);
    }
};
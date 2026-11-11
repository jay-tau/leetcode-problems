class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int writer = m + n - 1, left = m - 1, right = n - 1;

        for (int writer = m + n - 1; writer >= 0; writer--) {
            int a = INT_MIN, b = INT_MIN;
            
            if (left >= 0) a = nums1[left];
            if (right >= 0) b = nums2[right];

            if (a >= b) {
                nums1[writer] = a;
                left--;
            } else {
                nums1[writer] = b;
                right--;
            }
        }
    }
};
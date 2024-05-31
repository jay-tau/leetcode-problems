class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Iterate from behind
        
        int i1 = m-1, i2 = n-1, i = ((m + n) - 1);
        
        while ((i1 >= 0) || (i2 >= 0)) {
            int x1 = (i1 >= 0) ? nums1[i1] : INT_MIN;
            int x2 = (i2 >= 0) ? nums2[i2] : INT_MIN;
            
            if (x1 >= x2) {
                nums1[i] = x1;
                i1--;
            } else {
                nums1[i] = x2;
                i2--;
            }
            i--;
        }
    }
};
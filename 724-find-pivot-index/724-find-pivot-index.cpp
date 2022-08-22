class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Build prefix and suffix sums
        int n = nums.size();
        int prefix[n], suffix[n];
        prefix[0] = nums[0]; suffix[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        for (int i = (n-1)-1; i >= 0; i--) {
            suffix[i] = suffix[i+1] + nums[i];
        }
        // for (int i= 0; i<n;i++)
                // cout << suffix[i] << " ";
        int pivot = -1;
        for (int i = 0; i < n; i++) {
            int left_sum = (i==0) ? 0 : prefix[i-1];
            int right_sum = (i==(n-1)) ? 0 : suffix[i+1];
            if (left_sum == right_sum) {
                pivot = i;
                break;
            }
        }
        return pivot;
    }
};
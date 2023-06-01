class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return 0;
    if (n == 2) return (nums[0] > nums[1]) ? 0 : 1;

    int l = 0, r = n - 1;

    while (l <= r) {
      int mid = (l + r) / 2;

      int current_element = nums[mid];
      int left_element = ((mid - 1) <= -1) ? INT_MIN : nums[mid - 1];
      int right_element = ((mid + 1) >= n) ? INT_MIN : nums[mid + 1];

      if ((left_element < current_element) &&
          (current_element > right_element))  // Peak
        return mid;
      if ((left_element < current_element) &&
          (current_element < right_element))  // Increasing
        l = mid + 1;                          // Move right
      else                                    // Decreasing
        r = mid - 1;                          // Move left
    }
    return -1;  // Answer not found
  }
};
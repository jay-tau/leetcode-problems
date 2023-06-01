class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return 0;
    if (n == 2) return ((nums[0] > nums[1]) ? 0 : 1); // Return largest of 2 elements

    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      int current_element = nums[mid];
      int left_element = ((mid - 1) <= -1) ? INT_MIN : nums[mid - 1];
      int right_element = ((mid + 1) >= n) ? INT_MIN : nums[mid + 1];
      
      if ((left_element < current_element) && (current_element > right_element)) {
        cout << "exit inside" << endl;
        return mid;
      }
      
      if ((left_element > current_element) && (current_element > right_element)) // Decreasing
        r = mid; // Move left
      else
        l = mid + 1; // Move right
    }
    return (l-1);
  }
};
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    // From the back, move pointer till we find a drop, i.e. a[i] < a[i+1]. If
    // no drop is found, then sort array and return. Here we have implemented a
    // search for the last rise from the front.
    int n = nums.size();
    int i_break = -1;
    for (int i = 0; i < (n - 1); i++)
      if (nums[i] < nums[i + 1])
        i_break = i;

    if (i_break == -1) { // Fully descending from front
      sort(nums.begin(), nums.end());
      return;
    }

    // For the remaining elements, find the last occurance x (smallest element greater than a[i])
    int x = INT_MAX;
    int x_pos = -1;
    for (int i = i_break + 1; i < n; i++)
      if ((nums[i] > nums[i_break]) && (nums[i] <= x)) {
        x = nums[i];
        x_pos = i;
      }

      // cout << nums[i_break] << endl;
      
    // Swap nums[i] with x.
    swap(nums[i_break], nums[x_pos]);
      
    // Place remaining elements in tail, in ascending order. Since we maintain descending order property, we can simply reverse it
    sort(nums.begin() + (i_break + 1), nums.end());
  }
};
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();

    vector<int> freq(3, 0);
    for (int num : nums) freq[num]++;

    // 0 will be [0, freq[0])
    // 1 will be [freq[0], freq[0] + freq[1])
    // 2 will be [freq[0] + freq[1], freq[0] + freq[1] + freq[2])
    for (int i = 0; i < freq[0]; i++) nums[i] = 0;
    for (int i = freq[0]; i < (freq[0] + freq[1]); i++) nums[i] = 1;
    for (int i = (freq[0] + freq[1]); i < (freq[0] + freq[1] + freq[2]); i++)
      nums[i] = 2;
  }
};
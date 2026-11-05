class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int left = 0, right = n-1;

        while (i <= right) {
            int &x = nums[i];
            if (x == 0) {
                swap(x, nums[left]);
                left++;
                i++;
            } else if (x == 1) {
                i++;
            } else if (x == 2) {
                swap(x, nums[right]);
                right--;
            } else { // This should never happen
                cerr << "Number other that 0, 1, 2" << endl;
            }
        }
    }
};
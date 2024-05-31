class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Uses constant extra space but modifies list
        int n = nums.size() - 1;
        
        // Set the value as negative if the number at that index is already seen
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            
            if (nums[x-1] < 0)
                return x;
            else
                nums[x-1] *= -1;
        }
        
        return -1;
    }
};
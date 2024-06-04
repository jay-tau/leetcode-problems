class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // Pick an element. Score +1 for same, -1 for different.
        int score = 0, x = -1;
        
        for (int i = 0; i < n; i++) {
            if (score <= 0) {
                x = nums[i];
                score = 0;
            }
            
            if (nums[i] == x) score++;
            else score--;
        }
        
        // printf("DEBUG: x: {%d}", x);
        
        // Check if greater than n/2 after pick. Not required since majority element is guaranteed in Q.
        
        return x;
    }
};
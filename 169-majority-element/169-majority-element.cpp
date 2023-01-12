class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algoritm
        // O(2n) time and O(1) space
        int majority_element, current_element_score = 0;
        for (auto x: nums) {
            if (current_element_score == 0)
                majority_element = x;
            
            current_element_score += ((x == majority_element)? 1 : -1);
        }
        
        int majority_element_count = 0;
        
        for (auto x: nums)
            majority_element_count += (x == majority_element);
        
        int n = nums.size();
        return ((majority_element_count > (n/2)) ? majority_element : -1);
    }
};
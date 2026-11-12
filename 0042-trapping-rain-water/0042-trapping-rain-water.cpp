class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int water = 0;
        int left = 0, right = n - 1;
        int left_wall = INT_MIN, right_wall = INT_MIN;

        while (left <= right) {
            int left_height = height[left], right_height = height[right];

            if (left_height <= right_height) {
                left_wall = max(left_wall, left_height);
                water += (left_wall - left_height);
                left++;
            } else {
                right_wall = max(right_wall, right_height);
                water += (right_wall - right_height);
                right--;
            }
        }

        return water;
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return countPairs(nums, 0, n); // [start, end)
    }

    int countPairs(vector<int>& v, int start, int end) {
        int n = v.size();
        int mid = (start + end) / 2;

        if ((end - start) <= 1) // Single element
            return 0;

        // Sort the smaller subproblem
        int pairs = countPairs(v, start, mid) + countPairs(v, mid, end);

        // Logic
        int left = start, right = mid;

        // Count the pairs
        while ((left < mid) && (right < end)) {
            long long x_left = v[left], x_right = v[right];
            
            if (x_left > 2 * x_right) {
                pairs += (mid - left);
                right++;
            } else {
                left++;
            }
        }

        // Sort the array
        vector<int> temp;
        temp.reserve(end - start);
        left = start; right = mid;
        while ((left < mid) || (right < end)) {
           if (left == mid) {
            temp.emplace_back(v[right]);
            right++;
           } else if (right == end) {
            temp.emplace_back(v[left]);
            left++;
           } else if (v[left] <= v[right]) {
            temp.emplace_back(v[left]);
            left++;
           } else {
            temp.emplace_back(v[right]);
            right++;
           }
        }

        for (int i = 0; i < temp.size(); i++) {
            v[start + i] = temp[i];
        }

        return pairs;
    }
};
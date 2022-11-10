class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return false;
        
        vector<int> diff(n-1);
        for (int i = 0; i < (n-1); i++) {
            diff[i] = arr[i+1] - arr[i];
        }
        
        if (!(diff[0] > 0))
            return false;
        if (!(diff[n-2] < 0))
            return false;
        
        int count = 0;
        for (int i = 0; i < ((n-1)-1); i++) {
            int current_sign = diff[i] * diff[i + 1];
            if (!(current_sign > 0))
                count++;
        }
        if (count == 1)
             return true;
        else
             return false;
    }
};
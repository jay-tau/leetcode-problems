class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> d; // element, count
        for (int i = 0; i < arr.size(); i++) {
            d[arr[i]] += 1;
        }
        for (int i = 0; i < arr.size(); i++) {
            int current_element = arr[i];
            if (current_element == 0) {
                if (d[0] >= 2)
                    return true;
                else
                    continue;
            }
            
            if (d[2 * current_element] >= 1)
                return true;
        }
        return false;
    }
};
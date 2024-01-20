class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n-1;
        vector<int> answer(2);
        while (i <= j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                cout << i << " " << j << endl;
                answer[0] = (i+1);
                answer[1] = (j+1);
                break;
            }
            else if (sum > target)
                j--;
            else
                i++;
        }
        return answer;
    }
};
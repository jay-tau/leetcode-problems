class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();

    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    vector<int> previous_interval = intervals[0];
    for (int i = 1; i < n; i++) {
      vector<int>& current_interval = intervals[i];

      if (current_interval[0] <= previous_interval[1])
        previous_interval[1] = max(previous_interval[1], current_interval[1]);

      else {  // Push into answer before starting new interval
        ans.push_back(previous_interval);
        previous_interval = current_interval;
      }
    }

    ans.push_back(previous_interval);  // Last interval is pushed

    return ans;
  }
};
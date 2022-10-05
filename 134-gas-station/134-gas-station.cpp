class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

		int total_surplus = 0, current_surplus = 0;
		int start = 0;

		for (int i = 0; i < n; i++) {
			int surplus_i = (gas[i] - cost[i]);
			current_surplus += surplus_i;
			total_surplus += surplus_i;
			if (current_surplus < 0) {
				start = (i + 1);
				current_surplus = 0;
			}
		}

		if (((total_surplus < 0) || (start >= n)))
			return -1;
		else
			return start;
    }
};
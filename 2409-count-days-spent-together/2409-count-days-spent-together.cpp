class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> calendar = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        vector<int> month_offsets = {-1, 0}; // -1 makes it 1-indexed
        month_offsets.reserve(12 + 2); // Pre-reserve space
        for (int days_in_month: calendar)
            month_offsets.emplace_back(month_offsets.back() + days_in_month);


        auto dayIdx = [&month_offsets](const string &s) {
            return dayIdxHelper(s, month_offsets);
        };
        
        int alice_arrive_idx = dayIdx(arriveAlice), alice_leave_idx = dayIdx(leaveAlice);
        int bob_arrive_idx = dayIdx(arriveBob), bob_leave_idx = dayIdx(leaveBob);
        
        int days_diff = min(alice_leave_idx, bob_leave_idx) - max(alice_arrive_idx, bob_arrive_idx);

        return max(0, days_diff + 1);
    }

    static int dayIdxHelper(const string &date, const vector<int> &month_offsets) {
        int m = stoi(date.substr(0, 2));
        int d = stoi(date.substr(3, 4));

        return month_offsets[m] + d;
    }
};
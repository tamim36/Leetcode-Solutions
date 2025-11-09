class Solution {
public:
    int bestClosingTime(string customers) {
        int tot_y = 0;
        for (auto c : customers)
            tot_y += (c == 'Y') ? 1 : 0;

        int cur_y = 0, min_penalty = tot_y, hour_idx = 0;
        int cur_penalty = tot_y;

        for (int i = 0; i < customers.size(); i++) {
            cur_penalty += customers[i] == 'Y' ? -1 : +1;

            if (cur_penalty < min_penalty) {
                cout << "dhukse " << endl;
                min_penalty = cur_penalty;
                hour_idx = i + 1;
            }
        }

        return hour_idx;
    }
};
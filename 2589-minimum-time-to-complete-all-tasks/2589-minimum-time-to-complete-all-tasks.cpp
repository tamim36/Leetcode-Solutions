class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& t1, const auto& t2) {
        return t1[1] < t2[1];
        });

    vector<int> v(2001);
    int cnt = 0;

    for (auto task : tasks) {
        int st = task[0], end = task[1], d = task[2];

        for (int i = st; i <= end; i++) {
            if (v[i]) d--;
            else if (i+d-1 == end) {
                v[i] = 1;
                cnt++;
                d--;
                //cout << i << " st: " << st << "  end:" << end <<endl; 
            }
        }
    }

    return cnt;
    }
};
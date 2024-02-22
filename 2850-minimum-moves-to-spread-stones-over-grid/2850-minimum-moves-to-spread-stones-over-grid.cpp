class Solution {
public:
    string arrayToString(vector<int>& arr) {
    string arr_str = "";
    for (auto val : arr) {
        arr_str += to_string(val);
    }

    return arr_str;
}

vector<int> getNeighborsForOneDArray(int index) {
    vector<int> neighbors;
    if ((index + 1) % 3 != 0) neighbors.push_back(index + 1);
    if ((index % 3) != 0) neighbors.push_back(index - 1);
    if (index  <= 5) neighbors.push_back(index + 3);
    if (index  >= 3) neighbors.push_back(index - 3);

    return neighbors;
}

int minimumMoves(vector<vector<int>>& grid) {
    vector<int> one_d_grid(9);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            one_d_grid[i * 3 + j] = grid[i][j];
        }
    }

    unordered_set<string> unique_states;
    queue<string> q;
    string gridStr = arrayToString(one_d_grid);
    q.push(gridStr);
    unique_states.insert(gridStr);

    int moves = 0;
    while (!q.empty()) {
        int sz = q.size();
        
        for (int i = 0; i < sz; i++) {
            string cur_state = q.front(); q.pop();
            bool isValid = true;
            for (int k = 0; k < 9; k++) {
                if (cur_state[k] - '0' > 1) {
                    isValid = false;
                    for (auto nei : getNeighborsForOneDArray(k)) {
                        string new_state = cur_state;
                        new_state[k] = (int)new_state[k] - 1;
                        new_state[nei] = (int)new_state[nei] + 1;

                        if (!unique_states.count(new_state)) {
                            q.push(new_state);
                            unique_states.insert(new_state);
                        } 
                    }
                }
            }
            if (isValid)
                return moves;
        }
        moves++;
    }

    return moves;
}

};
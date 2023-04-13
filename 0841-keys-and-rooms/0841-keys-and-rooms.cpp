class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomNo = rooms.size()-1;
    unordered_set<int> vis;
    vector<int> keys(rooms[0]);
    vis.insert(0);

    while (!keys.empty())
    {
        int key = keys.back(); keys.pop_back();

        if (!vis.count(key)) {
            for (int k : rooms[key]) {
                if (!vis.count(k))
                    keys.push_back(k);
            }

            vis.insert(key);
            roomNo--;
        }
    }

    if (!roomNo) return true;
    return false;
    }
};
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
    int dis = 0, space = 0;
    for (auto c : moves){
        if (c == 'L') dis -= 1;
        else if (c == 'R') dis += 1;
        else space += 1;
    }

    return dis < 0 ? abs(dis - space) : dis + space;
}
};
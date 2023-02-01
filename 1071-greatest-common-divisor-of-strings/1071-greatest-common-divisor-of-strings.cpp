class Solution {
public:
    string modOfStrings(string a, string b) {
    if (a.size() < b.size()) return a;
    int rem = a.size() % b.size();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i % b.size()]) return "f";
    }

    return rem == 0 ? "" : a.substr(a.size() - rem, rem);
}

string gcdOfStrings(string a, string b) {
    if (a == "f" || b == "f") return "";
    return b == "" ? a : gcdOfStrings(b, modOfStrings(a, b));
}
};
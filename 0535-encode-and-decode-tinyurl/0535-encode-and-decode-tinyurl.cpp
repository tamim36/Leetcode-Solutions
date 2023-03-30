class Solution{
public:
    unordered_map<string, string> long_short;
    unordered_map<string, string> short_long;
    long long val = 0;
    string tinyUrl = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (!long_short.count(longUrl)) {
            string short_url = tinyUrl + to_string(val++);
            long_short[longUrl] = short_url;
            short_long[short_url] = longUrl;
        }
          
        return long_short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
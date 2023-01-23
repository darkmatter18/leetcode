class Solution {
    map<string, string> m;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        
        std::string tmp_s;
        tmp_s.reserve(6);

        for (int i = 0; i < 6; ++i) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        
        m.insert(pair<string, string>(tmp_s, longUrl));
        
        return tmp_s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
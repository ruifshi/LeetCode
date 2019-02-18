#include <string>
#include <map>

using namespace std;

class Solution {
public:
	// Encodes a URL to a shortened URL.
	string encode(string longUrl);

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl);

	map<int, string> table;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
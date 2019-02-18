#include "stdafx.h"
#include "EncodeAndDecodeTinyURL.h"

// Encodes a URL to a shortened URL.
string Solution::encode(string longUrl) {
	int i = rand();
	table.insert(pair<int, string>(i, longUrl));
	
	return "http://tinyurl.com/" + to_string(i);
}

// Decodes a shortened URL to its original URL.
string Solution::decode(string shortUrl) {
	string s = shortUrl.erase(0, strlen("http://tinyurl.com/"));
	int i = stoi(s);
	return table[i];
}
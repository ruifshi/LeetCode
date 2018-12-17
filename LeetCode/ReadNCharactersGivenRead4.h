// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
	int bp = 0;
	int len = 0;
	char buffer[4];
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Maximum number of characters to read
	 * @return    The number of characters read
	 */
	int read(char *buf, int n);
};
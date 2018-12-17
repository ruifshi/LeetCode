#include "stdafx.h"
#include "ReadNCharactersGivenRead4.h"

int read4(char *buf) {
	return 4;
}

/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
int Solution::read(char *buf, int n) {
	int i = 0;
	while (i < n) {
		if (bp == len) {
			bp = 0;
			len = read4(buffer);
			if (len == 0)
				break;
		}
		buf[i++] = buffer[bp++];
	}

	return i;
}
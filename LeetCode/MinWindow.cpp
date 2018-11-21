#include "stdafx.h"
#include "MinWindow.h"

char* minWindow(char* s, char* t) {
    char *front, *rear, *strindx;
	char *optimalFront = NULL;
    int inputLen, subLen, i;
    bool found = true;
    char *substring;
    int substringSize;
    int optimalSize = INT_MAX;
	int dict[256] = {0};
	int subDict[256] = {0};
    
    inputLen = strlen(s);
    subLen = strlen(t);
    
    if(inputLen < subLen) {
        return "";
    }
    
    substring = (char*)malloc(sizeof(char) * inputLen);
    
    front = s;
    rear = s + subLen;

	//dict = (int*)malloc(sizeof(int) * inputLen);
	//subDict = (int*)malloc(sizeof(int) * inputLen);

	//memset(dict, 0, sizeof(int) * 256);

	for(i = 0; i < subLen; i++) {
		dict[t[i]]++;
	}
    
    while((rear > front) && (rear <= (s + inputLen))) {
        found = true;
        substringSize = (int)(rear) - (int)(front);
        
        //strncpy(substring, front, substringSize);
		//substring[substringSize] = '\0';
        
		memset(subDict, 0, 256*sizeof(int));

		for(strindx = front; strindx < rear; strindx++) {
			subDict[strindx[0]]++;
		}

        for(i = 0; i < subLen; i++) {
            if(dict[t[i]] > subDict[t[i]])  {
                found = false;
                break;
            }
        }
        
        if(!found) {
            rear++;
            continue;
        }
        else {
            if(substringSize < optimalSize) {
                optimalSize = substringSize;
                optimalFront = front;
            }
            front++;
        }
    }

	if(optimalFront) {
		strncpy(substring, optimalFront, optimalSize);
		substring[optimalSize] = '\0';
		printf("%s", substring);
		return substring;
	}
	else
	{
		return "";
	}
}
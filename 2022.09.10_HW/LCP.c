#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * longestCommonPrefix(char ** strs, int strsSize)
{
   for(int c = 0; ;++c)
	{
		if(strs[0][c] == '\0') // the longest common prefix is the first string
        {
            return strs[0];
        }
		for(int s = 1; s < strsSize; ++s)
		{
			if(strs[s][c] != strs[0][c]) // compare all strings character to the first one
			{
				strs[0][c] = '\0'; // replace the current character with '\0'
				return strs[0];
			}
		}
	}
}

int main(int argc, char* argv[])
{
	char* strs[4];
    strs[0] = malloc(6 * sizeof(char));
    strcpy(strs[0], "leets");
    strs[1] = malloc(9 * sizeof(char));
    strcpy(strs[1], "leetcode");
    strs[2] = malloc(5 * sizeof(char));
    strcpy(strs[2], "leet");
    strs[3] = malloc(6 * sizeof(char));
    strcpy(strs[3], "leeds");
    longestCommonPrefix(strs, 4);
    printf("%s\n", strs[0]);


   return 0;
}
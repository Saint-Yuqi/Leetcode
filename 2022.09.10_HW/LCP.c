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
    char** strs = (char* []) {"leets", "leetcode", "leet", "leeds"};
    printf("%s",longestCommonPrefix(strs,4));
    return 1;
}

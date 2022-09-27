//rem.c == regular expression matching
//https://leetcode.com/problems/regular-expression-matching/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>



bool isMatch(char* s, char* p)
{
    int str = 0;
    int ptn = 0;
    str = strlen(s); //the length of the input string
    ptn = strlen(p); //the length of the pattern string 
    char dp[str][ptn];
    dp[0][0] = true;

    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < ptn; j++)
        {
            if (p[j] == '*') 
            {
                if (s[i] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j]; // means if a* works for current i , it may also works for latter i , so I don't gave up it.

                }
                else
                {
                    dp[i][j] = dp[i][j - 2]; // it means "a*" is equal to 0;
                }
            }
            else
            {
                if (p[j] == s[i] || p[j] == '.')
                {
                    if (i < 0)
                    {
                        return false;
                    }
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }

    return dp[str][ptn];

}

int main (int argc, char* argv[])
{
    char s[2] = {'a','a'};
    char p[2] = {'b','*'};
    if (isMatch(s, p) == true)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}
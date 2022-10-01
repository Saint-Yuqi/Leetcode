#include <stdio.h>
#include <string.h>
/*
Runtime: 24 ms, faster than 7.95% of C online submissions for Roman to Integer.
Memory Usage: 6 MB, less than 6.55% of C online submissions for Roman to Integer.
*/
int romanInteger(char s)
{ 
    switch(s){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;       
    }
}
int romanToInt(char * s)
{
    int sum = 0;
    int last = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        int current = romanInteger(s[i]);
        if ( current < last)
        {
            sum -= current;
        }
        else
        {
            sum += current;
        }

        last = current;
    }
        return sum;

}

int main(int argc, char *argv[])
{
    char s[] =  "";
    int a = 0;
    scanf("%s", s);
    a = romanToInt(s);
    printf("%d\n", a);
} 
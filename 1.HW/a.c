#include <stdio.h>
#include <stdbool.h>
/*Runtime: 31 ms, faster than 19.02% of C online submissions for Palindrome Number.
Memory Usage: 5.9 MB, less than 47.50% of C online submissions for Palindrome Number.
*/
bool isPalindrome(int x)
{
      
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int a = 0;
    
    while (x > a)
    {
        a = a * 10 + x % 10;
        x = x / 10;
    }
    if (a == x || (x == a / 10))
    {
        return true;
    }
    return 0;

}
int main(int argc, char *argv[])
{
    int x = 0;
    scanf("%d", &x);
    if(isPalindrome(x) == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
} 
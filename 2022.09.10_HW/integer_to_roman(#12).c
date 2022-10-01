#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Runtime: 10 ms, faster than 52.20% of C online submissions for Integer to Roman.
Memory Usage: 5.8 MB, less than 89.80% of C online submissions for Integer to Roman.
*/
char * integerRoman(int s)
{ 
    switch(s){
        case 1:
            return "I";
        case 5:
            return "V";
        case 10:
            return "X";
        case 50:
            return "L";
        case 100:
            return "C";
        case 500:
            return "D";           
        case 1000:
            return "M";
        default:
            return "";       
    }
}

char * intToRoman(int num)
{
    int i = 0;
    char* itr = (char*) malloc(sizeof(char)*20);
    memset (itr, 0, sizeof(char)*20);
    while (num > 0)
    {
        if (num >= 1000)
        {
            itr[i++] = * integerRoman(1000);
            num -= 1000;
        }
        else if (num >= 900)
        {
            itr[i++] = 'C';
            itr[i++] = 'M';
            num -= 900;
        }
        else if (num >= 500)
        {
            itr[i++] = * integerRoman(500);
            num -= 500;
        }
        else if (num >= 400)
        {
            itr[i++] = 'C';
            itr[i++] = 'D';
            num -= 400;
        }
        else if (num >= 100)
        {
            itr[i++] = * integerRoman(100);
            num -= 100;
        }
        else if (num >= 90)
        {
            itr[i++] = 'X';
            itr[i++] = 'C';
            num -= 90;
        }
        else if (num >= 50)
        {
            itr[i++] = * integerRoman(50);
            num -= 50;
        }
        else if (num >= 40)
        {
            itr[i++] = 'X';
            itr[i++] = 'L';
            num -= 40;
        }
        else if (num >= 10)
        {
            itr[i++] = * integerRoman(10);
            num -= 10;
        }
        else if (num >= 9)
        {
            itr[i++] = 'I';
            itr[i++] = 'X';
            num -= 9;
        }
        else if (num >= 5)
        {
            itr[i++] = * integerRoman(5);
            num -= 5;
        }
        else if (num >= 4)
        {
            itr[i++] = 'I';
            itr[i++] = 'V';
            num -= 4;
        }
        else if (num >= 1)
        {
            itr[i++] = * integerRoman(1);
            num -= 1;
        }
    }

    return itr;
}

int main(int argc, char* argv[])
{
    int num = 0;
    char* strs[1];
    scanf("%d", &num);
    strs[0] = malloc(20 * sizeof(char));
    strs[0] = intToRoman(num);
    printf("%s\n",strs[0]);
}
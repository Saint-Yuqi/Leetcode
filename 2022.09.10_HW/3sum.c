#include "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/malloc/_malloc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.(int *returnColumnSizes[]) 
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void exchange (int* a, int* b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int divide(int* arrays, int f, int l) //f:first element index l: last element index
{
    int divided_value = l;
    int divided_index = f;
    for (int k = f; k < l; k++)
    {
        if (arrays[k] <= arrays[divided_value]) // !!!!don't forget thie equivalent 
        {            
            exchange(&arrays[k], &arrays[divided_index]);
            divided_index++;
        }
    }
    exchange(&arrays[divided_value], &arrays[divided_index]);

    return divided_index;

}

void quickSort(int* arrays, int f, int l)
{   
    if (f < l)
    {
        int q = divide(arrays, f, l);
        quickSort(arrays, f, q - 1);
        quickSort(arrays, q + 1, l);

    }
}

/**  
 * (int** returnColumnSizes) would be (int *returnColumnSizes[]) 
 *  this would be an array of unspecified number of pointers to int in all other contexts,
 */ 


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (numsSize < 3) 
    {
        return 0;
    }
    quickSort(nums, 0, numsSize - 1);
    //ans is a 2D array, if we have 100 solutions, we need 100 space of pointer
    //every one pointer can point to one array which is one solution
    //(*returnSize) record how many solutions
    int **ans = (int **)malloc(sizeof(int*) * (*returnSize));
    //returnSize is one pointer, *returnSize is the value
    // I would use two-pointer to avoid the repeated number.
    *returnSize = 0;
    for (int i = 0; i < numsSize - 2; ++i)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int third = numsSize - 1;
        int target = -nums[i];

        for (int j = i + 1; j < numsSize - 1; ++j)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            while (nums[j] < nums[third] && nums[j] + nums[third] > target) 
            {
                --third;
            }

            if (j == third)
            {
                break;
            }

            if (nums[j] + nums[third] == target)
            {
                int *temp = (int *)malloc(sizeof(int) * 3);
                temp[0] = nums[i];
                temp[1] = nums[j];
                temp[2] = nums[third];
                ans[(*returnSize)++] = temp;         
            }

        }
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int k = 0; k < (*returnSize); k++)
    {
        *returnColumnSizes[k] = 3;    
    }
    return ans;
}

int main(int argc, char* argv[])
{
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
    int* returnSize;// the row of the 2D-array
    int** returnColumnSize;//the pointer to the pointer to the column array
    // Note：We don't know the column array,and we don't need to know
    // We only need know that one pointer point to iy
    int** ans = threeSum(nums, numsSize, returnSize, returnColumnSize);
    // &returnSize 
    // the same as: int *returnColumnSize，then &returnColumnSizes
    for (int i = 0; i < (*returnSize); i++) 
    {
        for (int j = 0; j < (*returnColumnSize)[i]; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;

}


/*
int *a. This is a pointer to an int.

int **a. This is a pointer to pointer to an int.

int a[] This would be an array of unspecified number of ints in all other contexts, but as a function parameter declarator, it is adjusted to be a pointer to int i.e. in that case it is same as if you had written int *a.

int a[][] This would be an array of unspecified number of arrays of unspecified number of ints, but such type is ill-formed because the array element cannot be an array of unspecified size.

int *a[] This would be an array of unspecified number of pointers to int in all other contexts, but as a function parameter declarator, it is adjusted to be a pointer to pointer to int i.e. in that case it is same as if you had written int **a.

int (*a)[N] This is a pointer to an array of N ints.

int a[][N] This would be an array of unspecified number of arrays of N ints in all other contexts, but as a function parameter declarator, it is adjusted to be a pointer to an array of N int i.e. in that case it is same as if you had written int (*a)[N].
*/
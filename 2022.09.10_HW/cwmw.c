// Container With Most Water == cwmw
#include <stdio.h>
/**
 *Runtime: 183 ms, faster than 30.07% of C online submissions for Container With Most Water.
 * Memory Usage: 11.7 MB, less than 57.50% of C online submissions for Container With Most Water.
 *
 */
int maxArea(int* height, int heightSize)
{
    int rightmost = heightSize - 1;
    int container = 0;
    int length = 0;
    for (int i = 0; i < heightSize;)
    {
        int length = rightmost - i;
        if (i == rightmost)
        {
            break;
        }
        if (height[i] <= height[rightmost])
        {
            if (container <= height[i] * (length))
            {
                container = height[i] * (length);
            }
            i++;
            continue;
        }
        if (height[i] > height[rightmost])
        {
            if (container <= height[rightmost] * (length))
            {
                container = height[rightmost] * (length);
            }
            rightmost--;
        }
    }
    return container;
}

int main(int argc, char* argv[])
{
    int height[7] = {2,3,4,5,18,17,6};
    int heightSize = 7;
    int a = 0;
    a = maxArea(height,heightSize);
    printf("%d\n",a);
}
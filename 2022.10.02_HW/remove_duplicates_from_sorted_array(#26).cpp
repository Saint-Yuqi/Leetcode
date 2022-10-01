#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int k = 1; // choose the second element in the array
        l = nums.size();
        if (l == 0)
        {
            return 0;
        }
        for (int i = 1; i < l; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[k] = nums[i];
                ++k;             
            }
        }
        return k;
    }
};
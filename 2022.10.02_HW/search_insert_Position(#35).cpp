//Runtime: 7 ms, faster than 68.22% of C++ online submissions for Search Insert Position.
//Memory Usage: 9.6 MB, less than 71.82% of C++ online submissions for Search Insert Position.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int i = 0;
        int mid = 0;
        l = nums.size();
        if (target > nums[l - 1])
        {
            return l;
        }
        
        if (target < nums[0])
        {
            return i;
        }

        while (i <= l)
        {
            mid = (i + l) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (target > nums[mid])
            {
                i = mid + 1;
            }
            else
            {
                l = mid - 1;
            }
        }

        if (target > nums[mid])
        {
            return mid + 1;
        }
        else
        {
            return mid;
        }
    }
};

int main()
{   int target = 7;
    vector<int> nums[4];
    nums->push_back(1);
    nums->push_back(3);
    nums->push_back(5);
    nums->push_back(6);
    cout << Solution::searchInsert(*nums, target) << endl;

}
#include <iostream>
#include <vector>

using namespace std;
//Runtime: 10 ms, faster than 5.76% of C++ online submissions for Remove Element.
//Memory Usage: 8.9 MB, less than 35.79% of C++ online submissions for Remove Element.
class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        
        int k = 0;
        int l = 0;
        l = nums.size();
        for (int i = 0; i < l; i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> nums[i];
    }
    int val = 0;
    int k = 0;
    val = 2;
    k = Solution::removeElement(nums,val) ;
    cout << k << endl;

}
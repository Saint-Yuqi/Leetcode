#include <iostream>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if (s == "")
       {
           return 0;
       }

       int r = 0;
       int l = 0;
       int longest = 0;
       int index[128] = {0};
       while (r < s.length() && l < s.length())
       {
           index[s[r]]++;
           if (index[s[r]] > 1)
           {
               index[s[l]]--;
               l++;
           }
           
           longest = max(longest, r - l +1);
           r++;
       }
       return longest;
        
    }
};
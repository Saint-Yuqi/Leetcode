//Runtime: 4 ms, faster than 44.89% of C++ online submissions for Length of Last Word.
//Memory Usage: 6.5 MB, less than 88.94% of C++ online submissions for Length of Last Word.
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if(s[i] == ' ' && k > 0) 
            {
                return k;
            }
            if (s[i] != ' ')
            {
                k++;
            }
        }
        return k;
    }
};
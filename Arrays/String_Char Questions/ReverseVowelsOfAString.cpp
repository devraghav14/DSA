// Leetcode Question No : 345 - Reverse Vowels of a string(Easy)

/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"



Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";

        while (start < end)
        {

            while (start < end && vowels.find(s[start]) == string::npos)
            {
                start++;
            }

            while (start < end && vowels.find(s[end]) == string::npos)
            {
                end--;
            }

            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};

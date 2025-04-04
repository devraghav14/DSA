// Leetcode Problem No 32 : Longest Valid Paranthesis (Hard)

/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0, maxLength = 0;
        for (char c : s)
        {
            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                maxLength = max(maxLength, 2 * right);
            else if (right > left)
                left = right = 0;
        }

        left = right = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                right++;
            else
                left++;

            if (left == right)
                maxLength = max(maxLength, 2 * left);
            else if (left > right)
                left = right = 0;
        }

        return maxLength;
    }
};
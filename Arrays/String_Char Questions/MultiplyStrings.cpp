// Leetcode Problem No 43 : Multiply Strings

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int len1 = num1.size(), len2 = num2.size();
        vector<int> result(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string product = "";
        for (int num : result)
        {
            if (!(product.empty() && num == 0))
            {
                product += (num + '0');
            }
        }

        return product.empty() ? "0" : product;
    }
};

// Leetcode Question No : 49 - Group Anagrams(Medium)

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]



Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> groupedAnagrams;

        for (int i = 0; i < strs.size(); i++)
        {
            string sortCurrWord = strs[i];
            sort(sortCurrWord.begin(), sortCurrWord.end());

            groupedAnagrams[sortCurrWord].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto it = groupedAnagrams.begin(); it != groupedAnagrams.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};
/*
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]
Constraints:

1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        vector<vector<int>> bucket(n + 1);
        for (auto it : freq)
        {
            bucket[it.second].push_back(it.first);
        }

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--)
        {
            for (int num : bucket[i])
            {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }
        return result;
    }
};

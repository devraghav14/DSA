/*
You are given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [2,-1,1,2], k = 2

Output: 4
Explanation: [2], [2,-1,1], [-1,1,2], [2] are the subarrays whose sum is equals to k.

Example 2:

Input: nums = [4,4,4,4,4,4], k = 4

Output: 6
Constraints:

1 <= nums.length <= 20,000
-1,000 <= nums[i] <= 1,000
-10,000,000 <= k <= 10,000,000

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];

            int remove = prefixSum - k;
            count += mp[remove];
            mp[prefixSum] += 1;
        }
        return count;
    }
};
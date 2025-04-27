// Leetcode Problem No - 239 : Sliding Window Maximum (Hard)

/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // traverse first window
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && (nums[i] >= nums[dq.back()]))
            {
                dq.pop_back();
            }
            // inserting index, to efficiently check next windows
            dq.push_back(i);
        }

        // store ans for first window
        ans.push_back(nums[dq.front()]);

        // process remaining windows
        for (int i = k; i < nums.size(); i++)
        {
            // remove out of window element
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && (nums[i] >= nums[dq.back()]))
            {
                dq.pop_back();
            }
            // inserting index, to efficiently check next windows
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
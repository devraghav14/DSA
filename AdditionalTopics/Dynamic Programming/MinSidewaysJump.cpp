// Leetcode Problem No : 1824 - Minimum Sideways Jump (Medium)

/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.



Example 1:


Input: obstacles = [0,1,2,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
Example 2:


Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
Example 3:


Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.


Constraints:

obstacles.length == n + 1
1 <= n <= 5 * 105
0 <= obstacles[i] <= 3
obstacles[0] == obstacles[n] == 0
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // int solve(vector<int>& obstacles, int currlane, int currpos ){ - Recursive Solution
    //     int n = obstacles.size() - 1;
    //     if(currpos == n) return 0;
    //     if(obstacles[currpos + 1] != currlane){
    //         return solve(obstacles, currlane, currpos + 1);
    //     }else{
    //         int ans = INT_MAX;
    //         for(int i = 1; i <= 3; i++){
    //             if(currlane != i && obstacles[currpos] != i)
    //                 ans = min(ans, 1 + solve(obstacles, i, currpos));

    //         }
    //         return ans;
    //     }
    // }
    // int solveMem(vector<int>& obstacles, int currlane, int currpos, vector<vector<int> >& dp){ - Top Down DP
    //     int n = obstacles.size() - 1;
    //     if(currpos == n) return 0;
    //     if(dp[currlane][currpos] != -1) return dp[currlane][currpos];
    //     if(obstacles[currpos + 1] != currlane){
    //         dp[currlane][currpos] = solveMem(obstacles, currlane, currpos + 1, dp);
    //         return dp[currlane][currpos];
    //     }else{
    //         int ans = INT_MAX;
    //         for(int i = 1; i <= 3; i++){
    //             if(currlane != i && obstacles[currpos] != i)
    //                 ans = min(ans, 1 + solveMem(obstacles, i, currpos, dp));

    //         }
    //         dp[currlane][currpos] = ans;
    //         return dp[currlane][currpos];
    //     }
    // }
    // int solveTab(vector<int>& obstacles){ // Bottom Up
    //     const int n = obstacles.size();
    // const int INF = 1e9;

    // vector<vector<int>> dp(4, vector<int>(n, INF));

    // dp[1][0] = 1;
    // dp[2][0] = 0;
    // dp[3][0] = 1;

    // for (int pos = 1; pos < n; ++pos) {
    //     for (int lane = 1; lane <= 3; ++lane) {

    //         if (obstacles[pos] == lane) {
    //             dp[lane][pos] = INF;
    //         } else {

    //             dp[lane][pos] = dp[lane][pos - 1];
    //         }
    //     }

    //     for (int lane = 1; lane <= 3; ++lane) {
    //         if (obstacles[pos] == lane) continue;
    //         for (int other = 1; other <= 3; ++other) {
    //             if (lane != other && obstacles[pos] != other) {
    //                 dp[lane][pos] = min(dp[lane][pos], dp[other][pos] + 1);
    //             }
    //         }
    //     }
    // }

    // return min({dp[1][n - 1], dp[2][n - 1], dp[3][n - 1]});
    // }
    int solveSO(vector<int> &obstacles)
    { // Space Optimized
        const int n = obstacles.size();
        const int INF = 1e9;

        vector<int> prev(4, INF);
        vector<int> curr(4, INF);

        // Initial position
        prev[1] = 1;
        prev[2] = 0;
        prev[3] = 1;

        for (int pos = 1; pos < n; ++pos)
        {
            for (int lane = 1; lane <= 3; ++lane)
            {
                if (obstacles[pos] == lane)
                {
                    curr[lane] = INF;
                }
                else
                {
                    curr[lane] = prev[lane];
                }
            }

            for (int lane = 1; lane <= 3; ++lane)
            {
                if (obstacles[pos] == lane)
                    continue;
                for (int other = 1; other <= 3; ++other)
                {
                    if (lane != other && obstacles[pos] != other)
                    {
                        curr[lane] = min(curr[lane], curr[other] + 1);
                    }
                }
            }

            prev = curr;
        }

        return min({prev[1], prev[2], prev[3]});
    }
    int minSideJumps(vector<int> &obstacles)
    {
        // return solve(obstacles, 2, 0);
        //  vector<vector<int> > dp(4, vector<int>(obstacles.size(), -1));
        //  return solveMem(obstacles, 2, 0, dp);
        //  return solveTab(obstacles);
        return solveSO(obstacles);
    }
};
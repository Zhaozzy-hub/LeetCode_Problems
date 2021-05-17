#include <vector>
#include <iostream>
using namespace std;


int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < target) return 0;
    if (nums.size() == 1 and (nums[0] == target || nums[0] == -target)) {
        return 1;
    }
    else if (nums.size() == 1 and nums[0] != target) {
        return 0;
    }
    int m = 2 * sum + 1;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(m, 0));
    dp[0][sum] = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] != 0) {
                if (nums[i] == 0) {
                    dp[i + 1][j] = dp[i][j] * 2;
                    continue;
                }
                if ((j - nums[i]) >= 0 and (j + nums[i]) < m) {
                    dp[i + 1][j - nums[i]] += dp[i][j];
                    dp[i + 1][j + nums[i]] += dp[i][j];
                }
                if ((j - nums[i]) < 0 and (j + nums[i]) < m) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                }
                if ((j - nums[i]) > 0 and (j + nums[i]) >= m) {
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
                continue;
            }
        }
    }

    return dp[nums.size()][target + sum];
}

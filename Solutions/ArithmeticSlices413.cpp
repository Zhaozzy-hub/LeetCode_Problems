#include <iostream>
#include <vector>
using namespace std;


int numberOfArithmeticSlices(vector<int>& nums) {
    int len = nums.size();
    if (len < 3) return 0;
    vector<int> dp(len, 0);
    int diff = nums[1] - nums[0];
    int pre = 0;
    for (int i = 2; i < len; i++) {
        if (nums[i] - nums[i - 1] == diff) {
            dp[i] = dp[i - 1] + i - pre - 1;
        }
        else {
            dp[i] = dp[i - 1];
            pre = i - 1;
            diff = nums[i] - nums[i - 1];
        }
    }
    return dp[len - 1];
}
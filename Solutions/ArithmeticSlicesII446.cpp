#include <iostream>
#include <vector>
#include <map>
using namespace std;


// dp[i][diff] := the number of subsequences ends in i with diff (length >=2)
int numberOfArithmeticSlices(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    if (n < 3) return 0;
    vector<map<long long, int>> dp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long diff = (long long)nums[i] - (long long)nums[j];
            // add a sequence with length = 2;
            dp[i][diff] += 1;
            // if sequence with diff already exist
            if (dp[j].find(diff) != dp[j].end()) {
                // add all subsequnce
                dp[i][diff] += dp[j][diff];
                ans += dp[j][diff];
            }
        }
    }
    return ans;
}
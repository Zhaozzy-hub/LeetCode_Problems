#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (nums[i] < nums[i - 1] + nums[i - 2])ans = nums[i - 1] + nums[i - 2] + nums[i];
    }
    return ans;
}
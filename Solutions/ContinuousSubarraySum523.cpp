#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;





bool checkSubarraySum(vector<int>& nums, int k) {
    int len = nums.size();
    unordered_map<int, int> m{ {0,-1} };
    int r = 0;
    for (int i = 0; i < len; i++) {
        r += nums[i];
        r %= k; // reminder of sum(nums[0~i])
        if (m.count(r)) {
            if (i - m[r] > 1) return true; // exists same reminder before which means sum(nums[0~i])% k == sum(nums[0~j])% k => sum(nums[i~j]) %k == 0
        }
        else {
            m[r] = i;
        }
    }

    return false;
}
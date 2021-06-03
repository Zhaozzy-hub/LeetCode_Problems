#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int len = nums.size();
    int sublen = l.size();
    vector<bool> ans;
    for (int i = 0; i < sublen; i++) {
        vector<int> tmp = { nums.begin() + l[i],nums.end() - (len - r[i] - 1) };
        sort(tmp.begin(), tmp.end());
        int diff = tmp[1] - tmp[0];
        for (int j = 1; j < tmp.size(); j++) {
            if (diff != tmp[j] - tmp[j - 1]) {
                ans.push_back(false);
                break;
            }
            if (j == tmp.size() - 1) {
                ans.push_back(true);
            }
        }

    }
    return ans;
}
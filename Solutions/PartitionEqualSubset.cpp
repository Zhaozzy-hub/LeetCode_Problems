#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


bool canpartition(vector<int>& nums) {
	int sum=0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	if (sum % 2 != 0) {
		return false;
	}
	int C = sum / 2;
	int n = nums.size();
	vector<vector<int>> tab(n + 1, vector<int>(C + 1));
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= C; k++) {
			if (j == 0 || k == 0) {
				tab[j][k] = 0;
			}
			else if (nums[j-1] <= k) {
				tab[j][k] = max(tab[j - 1][k], tab[j-1][k-nums[j-1]] + nums[j - 1]);
			}
			else {
				tab[j][k] = tab[j - 1][k];
			}
		}
	}

	if (tab[n][C] == C) {
		return true;
	}
	else {
		return false;
	}
}




int main() {
	vector<int> nums = { 2,2,1,1 };
	cout << canpartition(nums) << endl;

}
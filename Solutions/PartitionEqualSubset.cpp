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
			if (k == 0 || j == 0) {
				tab[j][k] = false;
			}
			else if (nums[j - 1] == k) {
				tab[j][k] = true;
			}
			else if (nums[j - 1] < k) {
				tab[j][k] = tab[j - 1][k - nums[j - 1]] || tab[j - 1][k];
			}
			else {
				tab[j][k] = tab[j - 1][k];
			}
		}
	}

	return tab[n][C];
}




//int main() {
//	vector<int> nums = { 2,2,1,1 };
//	cout << canpartition(nums) << endl;
//
//}
#include <vector>
#include <iostream>
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


bool canPart1D(vector<int>& nums) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	if (sum % 2 != 0) {
		return false;
	}
	int C = sum / 2;
	int n = nums.size();
	vector<int> tab(C + 1);
	tab[0] = true;
	if (nums[0] <= C) {
		tab[nums[0]] = true;
	}
	for (int i = 1; i < n; i++) {
		for (int k = C; k >= 0 && nums[i] <= k; k--) {
			tab[k] = tab[k] || tab[k - nums[i]];
		}
		if (tab[C]) {
			return tab[C];
		}
		
	}

	return tab[C];
}



int main() {
	vector<int> nums = { 1,5,11,5 };
	cout << canPart1D(nums) << endl;

}
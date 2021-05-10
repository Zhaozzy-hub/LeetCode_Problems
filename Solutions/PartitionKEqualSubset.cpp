#include <vector>
#include <iostream>
#include<Algorithm>
using namespace std;

bool backtrack(int target, vector<int>& nums, vector<bool> visited, int it,int k, int cur) {
	if (k == 1) {
		return true;
	}
	if (cur == target) {
		return backtrack(target, nums, visited, 0, k - 1, 0);
	}
	if (cur > target) {
		return false;
	}

	for (int i = it; i < nums.size(); i++) {
		if  (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])
			continue;
		if (visited[i] ) {
			visited[i] = false;
			if (backtrack(target, nums, visited, i+1, k, cur + nums[i])) {
				return true;
			}
			visited[i] = true;
		}
	}

	return false;
}


bool PartitionKEqualSubset(vector<int>& nums,int k) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	if (sum % k != 0) {
		return false;
	}
	int m = sum / k;

	vector<bool> visited(nums.size(), true);
	
	
	return backtrack(m, nums, visited, 0, k, 0);

}


//int main() {
//	vector<int> nums1 = { 1,1,1,1,1,1,1,1,1,1 };
//	vector<int> nums2 = { 2,2,2,2,3,4,5 };
//	vector<int> nums3 = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3 };
//	
//	cout << PartitionKEqualSubset(nums1, 5) << endl;
//	cout << PartitionKEqualSubset(nums2, 4) << endl;
//	cout << PartitionKEqualSubset(nums3, 8) << endl;
//}
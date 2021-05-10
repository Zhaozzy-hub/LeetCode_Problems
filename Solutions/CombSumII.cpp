#include <vector>
#include <iostream>
#include <Algorithm>
using namespace std;

void backtrack(vector<int>& candidates, vector<vector<int>>& l,int target, vector<int> cur, int k) {
	if (target == 0) {
		l.push_back(cur);
	}
	else if (target < 0) {
		return;
	}
	for (int i = k; i < candidates.size(); i++) {
		if (i > k && candidates[i] == candidates[i - 1]) continue;
		cur.push_back(candidates[i]);
		backtrack(candidates, l, target - candidates[i], cur, i + 1);
		cur.pop_back();
	}

	return;
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
	sort(candidates.begin(), candidates.end());
	vector<int> cur;
	vector<vector<int>> l;
	backtrack(candidates, l, target, cur, 0);
	return l;

}

//void printer(vector<vector<int>> v) {
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v[i].size(); j++) {
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//int main() {
//	vector<int> candidates = { 1,1,1,1,1,1,1,1,1,1 };
//	printer(combinationSum2(candidates, 2));
//
//
//}
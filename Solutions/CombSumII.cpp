#include <vector>
#include <iostream>
#include <Algorithm>
using namespace std;

void backtrack(vector<int>& candidates,int target, vector<int> cur, vector<vector<int>>& l,int pos) {
	if (target == 0) {
		l.push_back(cur);
		return;
	}


	for (int i = pos; i < candidates.size(); i++) {
		if (i > pos && candidates[i] == candidates[i - 1]) continue ;
		if (target - candidates[i] >= 0) {
			cur.push_back(candidates[i]);
			backtrack(candidates, target - candidates[i], cur, l, i+1);
			cur.pop_back();
		}
		
	}
	return;
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> l;
	vector<int> cur;
	int pos = 0;
	backtrack(candidates, target, cur, l, pos);
	return l;
}

void printer(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

//int main() {
//	vector<int> candidates = { 10,1,2,7,6,1,5 };
//	printer(combinationSum2(candidates, 8));
//
//
//}
#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool canSum(int n, vector<int> a) {
	if (n == 0)
	{
		return true;
	}
	if (n < 0)
	{
		return false;
	}
	
	for (int i = 0; i < a.size(); i++) {
		if (canSum(n - a[i], a)) {
			return true;
		}
	}
	return false;
}

bool dp_canSum(int n, vector<int> a,map<int, bool> &memo) {
	if (memo.find(n) != memo.end()) {
		return memo[n];
	}
	if (n == 0)
	{
		return true;
	}
	if (n < 0)
	{
		return false;
	}

	for (int i = 0; i < a.size(); i++) {
		if (dp_canSum(n - a[i], a, memo)) {
			memo[n] = true;
			return true;
		}
	}
	memo[n] = false;
	return false;
}


int main()
{
	vector<int> a = { 7,14 };
	map<int, bool> m;
	cout << dp_canSum(300, a, m) << endl;
	//cout << canSum(300, a) << endl;
}

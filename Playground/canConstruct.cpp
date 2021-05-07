#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;


bool canConstruct(string target, vector<string> bank, map<string, bool> &memo) {
	if (memo.find(target) != memo.end()) {
		return memo[target];
	}
	if (target.compare("")==0) {
		return true;
	}

	for (int i = 0; i < bank.size(); i++) {
		string word = bank[i];
		if (target.find(word) == 0) {
			string subtarget = target.substr(word.size());
			if (canConstruct(subtarget, bank, memo)) {
				memo[target] = true;
				return true;
			}
		}
	}


	memo[target] = false;
	return false;
}


//int main() {
//
//
//	map<string, bool> memo1;
//	vector<string> vec1 = { "ab","abc","cd","def","abcd" };
//	cout << canconstruct("abcdef",vec1 , memo1) << endl;
//	map<string, bool> memo2;
//	vector<string> vec2 = { "e","ee","eee","eeee","eeeee","eeeeeeeee" };
//	cout << canconstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", vec2, memo2) << endl;
//
//
//}
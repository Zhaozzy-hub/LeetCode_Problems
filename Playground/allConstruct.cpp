#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;


vector<string> allConstruct(string target, vector<string> bank, map<string,vector<string>>& memo) {
	
	if (target.compare("") == 0) {
		vector<string> emp = { "" };
		return emp;
	}
	if (memo.find(target) != memo.end()) {
		return memo[target];
	}
	vector<string> r = {};

	for (int i = 0; i < bank.size(); i++) {
		string word = bank[i];
		if (target.find(word) == 0) {
			string subtarget = target.substr(word.size());
			vector<string> subways = allConstruct(subtarget, bank,memo);
			vector<string> targetways = subways;
			for (int j = 0; j < targetways.size(); j++) {
				targetways[j] = word + " "+ targetways[j];
			}
			r.insert(r.end(), targetways.begin(), targetways.end());
		}
		
		
	}

	memo[target] = r;
	return r;
	

}


void printer(vector<string> r) {
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << endl;
		
	}
}

//int main() {
//	map<string, vector<string>> memo1;
//	string target1 = "abcdef";
//	vector<string> bank1= { "ab","abc","cd","def","abcd","ef","c" };
//	vector<string> r1 = allConstruct(target1, bank1,memo1);
//	printer(r1);
//
//	map<string, vector<string>> memo2;
//	string target2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz";
//	vector<string> bank2 = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa" };
//	vector<string> r2 = allConstruct(target2, bank2,memo2);
//	printer(r2);
//
//	map<string, vector<string>> memo3;
//	string target3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//	vector<string> bank3 = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa" };
//	vector<string> r3 = allConstruct(target3, bank3,memo3);
//	printer(r3);
//}
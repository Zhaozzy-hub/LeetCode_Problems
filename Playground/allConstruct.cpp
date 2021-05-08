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


vector<string> tab_allConstruct(string target, vector<string> bank) {
	vector<vector<string>> tab(target.size()+1, vector<string>());
	tab[0] = { "" };

	for (int i = 0; i <= target.size(); i++) {
		if (tab[i].size() > 0) {
			for (int j = 0; j < bank.size(); j++) {
				int m = bank[j].length();
				if (i + m <= target.size()) {
					if (target.substr(i, bank[j].size()).compare(bank[j]) == 0) {
						vector<string> tmp = tab[i];
						for (int k = 0; k < tab[i].size(); k++) {
							tmp[k] += " " + bank[j];
						}
						tab[i + m].insert(tab[i + m].end(), tmp.begin(), tmp.end());
						
					}
				}
			}
			
		}
	}
	return tab[target.size()];
}


void printer(vector<string> r) {
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << endl;
		
	}
}

int main() {
	map<string, vector<string>> memo1;
	string target1 = "abcdef";
	vector<string> bank1= { "ab","abc","cd","def","abcd","ef","c" };
	vector<string> r1 = tab_allConstruct(target1, bank1);
	printer(r1);
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
}
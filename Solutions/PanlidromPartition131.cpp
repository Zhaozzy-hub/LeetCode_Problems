#include <vector>
#include <iostream>
using namespace std;


bool ifpalidrome(string s) {
    if (s.length() == 1) {
        return true;
    }
    bool tmp = true;
    for (int i = 0; i <= s.length() / 2; i++) {
        tmp = tmp and (s[i] == s[s.length() - i - 1]);
    }

    return tmp;
}

void solver(string s, vector<vector<string>>& dp, vector<string> cur) {
    if (s.length() == 0) {
        dp.push_back(cur);
    }
    for (int i = 0; i < s.length(); i++) {
        if (ifpalidrome(s.substr(0, i + 1))) {
            cur.push_back(s.substr(0, i + 1));
            solver(s.substr(i + 1, s.length()), dp, cur);
            cur.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
    vector<vector<string>> dp;
    vector<string> cur;
    solver(s, dp, cur);
    return dp;
}
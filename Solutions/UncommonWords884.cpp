#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    unordered_map<string, int> dc;
    vector<string> ans;
    string tmp1 = "";
    string tmp2 = "";
    for (int i = 0; i < m; i++) {
        if (s1[i] == ' ' || i == m - 1) {
            if (i == m - 1) tmp1 = tmp1 + s1[i];
            dc[tmp1] += 1;
            tmp1 = "";
        }
        else {
            tmp1 = tmp1 + s1[i];
        }
    }
    for (int j = 0; j < n; j++) {
        if (s2[j] == ' ' || j == n - 1) {
            if (j == n - 1) tmp2 = tmp2 + s2[j];
            dc[tmp2] += 1;
            tmp2 = "";
        }
        else {
            tmp2 = tmp2 + s2[j];
        }
    }
    unordered_map<string, int>::iterator k;
    for (auto k = dc.begin(); k != dc.end(); k++) {
        if (k->second == 1) {
            ans.push_back(k->first);

        }

    }
    return ans;
}
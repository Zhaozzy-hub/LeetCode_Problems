#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool closeStrings(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    if (len1 != len2) return false;
    vector<int> a(26, 0);
    vector<int> b(26, 0);

    for (int i = 0; i < len1; i++) {
        a[word1[i] - 'a']++;
        b[word2[i] - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
        if (a[j] > 0 && b[j] == 0) return false;
        if (b[j] > 0 && a[j] == 0) return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int k = 0; k < 26; k++) {
        if (a[k] != b[k]) return false;
    }

    return true;
}
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

//slow 
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n, n);
    for (int i = 0; i < n; i++) {
        if (ifpalidrome(s.substr(0, i + 1))) {
            dp[i] = 0;
        }
        else
        {
            for (int j = 0; j < i; j++) {
                if (ifpalidrome(s.substr(j + 1, i - j))) {

                    dp[i] = min(dp[i], dp[j] + 1);
                }

            }
        }
    }
    return dp[n - 1];
}
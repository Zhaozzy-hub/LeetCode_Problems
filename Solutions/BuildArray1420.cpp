#include <iostream>
#include <vector>
using namespace std;


int numOfArrays(int n, int m, int k) {
    vector<vector<vector <long long>>> dp(n, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
    // set modulo modifier
    long long M = 1e9 + 7;
    // dp[i][j][k] the ans of arrs of length n, max of j(appeared) and k updates;

    //initial cases when length is 1 and cost is 1, there is only 1 possible way for any max
    for (int i = 1; i <= m; i++) {
        dp[0][i][1] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l <= k; l++) {

                // the ith element is larger than the first i-1 elements;
                for (int p = 1; p <= j - 1; p++) {
                    dp[i][j][l] += dp[i - 1][p][l - 1] % M;
                }
                // the ith element is smaller than the max within the first i-1 elements;
                dp[i][j][l] += dp[i - 1][j][l] * j % M;
            }
        }
    }
    long long ans = 0;
    for (int s = 1; s <= m; s++) {
        ans += dp[n - 1][s][k] % M;
    }
    return ans % M;
}
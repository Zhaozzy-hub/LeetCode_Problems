#include <vector>
#include <iostream>
using namespace std;

int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
    int numbooks = books.size();
    vector<int> dp(numbooks, INT_MAX);
    for (int i = 0; i < numbooks; i++) {
        int w = 0;
        int h = 0;
        for (int j = i; j >= 0; j--) {
            if ((w += books[j][0]) > shelf_width) break;
            h = max(h, books[j][1]);
            dp[i] = min((j == 0 ? 0 : dp[j - 1]) + h, dp[i]);
        }
    }
    return dp[numbooks - 1];
}
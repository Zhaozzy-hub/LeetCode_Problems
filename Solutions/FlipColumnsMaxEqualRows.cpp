#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm> 
using namespace std;


int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int ans = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    map<string, int> map;
    for (auto& row : matrix) {
        string boolrow = "";
        for (int i = 1; i < row.size(); i++) {
            boolrow += row[0] == row[i] ? '0' : '1';
        }
        map[boolrow]++;
    }

    for (auto& i : map) {
        ans = max(ans, i.second);
    }
    return ans;
}
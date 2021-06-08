#include <vector>
#include <iostream>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 1) return mat[0][0];
    int  i = 0;
    int left = 0;
    int right = 0;
    while (i < n) {
        left += mat[i][i];
        if (i != n - i - 1) right += mat[i][n - i - 1];
        i++;
    }
    return left + right;
}

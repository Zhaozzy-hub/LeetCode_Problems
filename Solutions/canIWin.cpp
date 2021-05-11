#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool solve(int state, int desiredTotal, vector<char>& m, int maxChoosableInteger) {
    if (desiredTotal <= 0) return false;
    if (m[state]) {
        return m[state] == 1;
    }
    for (int i = 0; i < maxChoosableInteger; i++) {
        if (state & (1 << i))continue;
        if (!solve(state | (1 << i), desiredTotal - i - 1, m, maxChoosableInteger)) {
            return m[state] = 1;
        }


    }
    m[state] = -1;
    return false;
}


bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
        return false;
    }
    if (desiredTotal <= 0) return true;
    vector<char>m(1 << maxChoosableInteger, 0);
    return solve(0, desiredTotal, m, maxChoosableInteger);
}


int main() {
	cout << canIWin(20, 152) << endl;
}
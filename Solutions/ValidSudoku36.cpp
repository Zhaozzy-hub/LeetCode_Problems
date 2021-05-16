#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<string, int> seen;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                string s(1, board[i][j]);
                string row = s + "seen in row" + to_string(i);
                string col = s + "seen in col" + to_string(j);
                string box = s + "seen in box" + to_string(i / 3) + to_string(j / 3);
                if ((seen.find(row) != seen.end()) || (seen.find(col) != seen.end()) || (seen.find(box) != seen.end())) return false;
                else {
                    seen[row] = 1;
                    seen[col] = 1;
                    seen[box] = 1;
                }
            }
        }
    }
    return true;

}

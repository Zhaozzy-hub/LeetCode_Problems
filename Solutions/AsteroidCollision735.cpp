#include <vector>
#include <iostream>
using namespace std;


vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;
    for (int i = 0; i < asteroids.size(); i++) {
        if (i == 0 || stack.size() == 0) {
            stack.push_back(asteroids[i]);
            continue;
        }
        if (stack[stack.size() - 1] > 0 && asteroids[i] < 0) {
            stack.push_back(asteroids[i]);
            for (int j = stack.size() - 2; j >= 0; j--) {
                if (stack[j] > 0 && stack[j + 1] < 0) {
                    if (stack[j] == -stack[j + 1]) {
                        stack.pop_back();
                        stack.pop_back();
                        break;
                    }
                    else {
                        stack[j] = stack[j] > -stack[j + 1] ? stack[j] : stack[j + 1];
                    }
                    stack.pop_back();
                }
                else {
                    break;
                }
            }

        }
        else {
            stack.push_back(asteroids[i]);
            continue;
        }
    }
    return stack;
}
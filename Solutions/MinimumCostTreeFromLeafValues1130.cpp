#include <vector>
#include <iostream>
#include <stack>
using namespace std;


int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    s.push(INT_MAX);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (s.top() <= arr[i]) {
            int pop = s.top();
            s.pop();
            ans += pop * min(s.top(), arr[i]);
        }
        s.push(arr[i]);
    }
    while (s.size() > 2) {
        int pop = s.top();
        s.pop();
        ans += pop * s.top();
    }
    return ans;
}
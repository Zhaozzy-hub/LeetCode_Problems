#include <vector>
#include <iostream>
using namespace std;


int maxScore(vector<int>& arr, int k) {
    int n = arr.size();
    int j = 0, sum = 0, sublen = 0, minSum = INT_MAX, tot = 0;
    for (int i = 0; i < arr.size(); i++) {
        tot += arr[i];
        sum += arr[i];
        sublen++;
        if (sublen == n - k) {
            minSum = min(minSum, sum);
            sum -= arr[j];
            j++;
            sublen--;
        }
    }
    if (n - k == 0)return tot;
    return tot - minSum;
}


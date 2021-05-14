#include <vector>
#include <iostream>
#include <map>
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    map<int, int>m;
    for (int i = 0; i < arr.size(); i++) {
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]] += 1;
        }
        else {
            m[arr[i]] = 1;
        }
    }
    map<int, int>n;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        n[it->second] = it->first;
    }
    if (m.size() == n.size()) {
        return true;
    }
    return false;
}
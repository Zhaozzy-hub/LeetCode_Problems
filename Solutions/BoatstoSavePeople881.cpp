#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// greedy, sort 
int numRescueBoats(vector<int>& people, int limit) {
    int k = 0;
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;
    while (start < end) {
        if (people[start] + people[end] <= limit) {
            start++;
            end--;
            k++;
        }
        else {
            end--;
            k++;
        }
    }
    if (start == end) {
        k++;
    }
    return k;
}
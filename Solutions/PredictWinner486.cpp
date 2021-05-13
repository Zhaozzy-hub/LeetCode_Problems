#include <vector>
#include <iostream>
#include <map>
using namespace std;


map<pair<int, int>, int> m;
int solve(int head, int tail, vector<int>& nums, map<pair<int, int>, int>& m) {
    if (head == tail) {
        m[{head, tail}] = nums[head];
        return nums[head];
    }
    if (m.find({ head,tail }) != m.end()) {
        return m[{head, tail}];
    }
    int cur = max(nums[head] - solve(head + 1, tail, nums, m), nums[tail] - solve(head, tail - 1, nums, m));
    m[{head, tail}] = cur;
    return cur;

}

bool PredictTheWinner(vector<int>& nums) {


    return solve(0, nums.size() - 1, nums, m) >= 0;
}

//int main() {
//    vector<int> nums = { 1,5,233,7 };
//    cout << PredictTheWinner(nums) << endl;
//
//}
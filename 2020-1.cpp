#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> nums;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<int> res;
    for(int i = 1; i <= n - 1; i ++) {// 1 5 6 9 10, 2
        if(nums[i] - nums[i - 1] >= d) res.push_back(nums[i]);
    }
    for(int i = 0; i < n; i ++) {
        cout << nums[i] << endl;
    }
    return 0;
}
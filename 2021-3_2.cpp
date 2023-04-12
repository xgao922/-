#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//位运算，数组中的全部元素的异或运算结果即为数组中只出现一次的数字
//时间复杂度：O(n)
//空间复杂度：O(1)
int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
    int ret = 0;
    for(auto e : nums) ret ^= e;
    cout << ret << endl;
    return 0;
}
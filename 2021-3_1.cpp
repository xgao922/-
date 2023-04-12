#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

//时间复杂度：O(n)
//空间复杂度：O(n)
int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i ++) {
        if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = 1;
        else mp[nums[i]] ++;
    }
    for(auto it = mp.begin(); it != mp.end(); it ++) {
        if(it->second == 1) cout << it->second << endl;
    }
    return 0;
}
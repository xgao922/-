#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

string LCS(string str1, string str2) {
    vector<vector<int>> dp(str1.size() + 1, vector<int> (str2.size() + 1, 0));
    string s = "";
    int result = 0;
    for(int i = 1; i <= str1.size(); i ++){
        for(int j = 1; j <= str2.size(); j ++){
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(dp[i][j] > result) {
                result = dp[i][j];
            }
        }
    }

    int i = str1.size(), j = str2.size();
    while(i >= 1 && j >= 1) {
        if(str1[i - 1] == str2[j - 1]){
            i --, j --;
            s += str1[i];
        }else if(dp[i][j] == dp[i - 1][j]) i--;
        else j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string str1;
    string str2;
    // string str3;
    cin >> str1 >> str2;
    string l1 = LCS(str1, str2);
    // string l2 = LCS(str2, str3);
    // string l3 = LCS(l1, l2);
    cout << l1 << endl;
    return 0;
}
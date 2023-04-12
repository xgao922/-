#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

string LCS3(string str1, string str2, string str3) {
    vector<vector<vector<int> > > dp(str1.size() + 1, vector<vector<int> > (str2.size() + 1, vector<int> (str3.size() + 1, 0)));
    string s = "";
    int result = 0;
    for(int i = 1; i <= str1.size(); i ++){
        for(int j = 1; j <= str2.size(); j ++){
            for (int k = 1; k <= str3.size(); k ++) {
                if(str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max( {dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]} );
                }
            }
        }
    }

    int i = str1.size(), j = str2.size(), k = str3.size();
    while (i >= 1 && j >= 1 && k >= 1) {
        if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
            s += str1[i - 1];
            i --, j --, k --;
        } else {
            if (dp[i][j][k] == dp[i - 1][j][k]) {
                i --;
            } else if (dp[i][j][k] == dp[i][j - 1][k]) {
                j --;
            } else {
                k --;
            }
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string str1;
    string str2;
    string str3;
    cin >> str1 >> str2 >> str3;
    cout << LCS3(str1, str2, str3) << "\n";
    return 0;
}
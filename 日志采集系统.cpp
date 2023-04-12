#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> Tn;
    int T;
    while(cin >> T)
        Tn.push_back(T);
    vector<int> dp;
    int temp, i;
    int sum = 0, score = 0;
    for(i = 0; i < Tn.size(); i ++) {
        sum += Tn[i];
        if(sum <= 100) dp.push_back(sum - score);
        else {
            temp = 100 - score;
            dp.push_back(temp);
            break;
        }
        score += Tn[i] * (i + 1);
    }
    int max = 0;
    for(int j = 0; j <= i; j ++) {
        if(dp[j] > max) max = dp[j];
    }
    cout << max << endl;
    return 0;
}
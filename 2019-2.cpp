#include <iostream>
#include <math.h>

using namespace std;

const int N = 1e6+10;
int nums[N];
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    int dp[n];
    dp[0] = nums[0];
    int result = nums[0];
    for(int i = 1; i < n; i ++){
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        if(dp[i] > result) result = dp[i];
    }
    cout << result << endl;
    return 0;
}
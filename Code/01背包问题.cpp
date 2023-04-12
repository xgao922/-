#include <iostream>
#include <fstream>

using namespace std;

const int N = 1010;
int v[N], w[N];
int dp[N][N];

int main() {
    ifstream iFile;
    iFile.open("in.txt");
    int n, m;//n为物品数量，m为背包容积
    iFile >> n >> m;
    for(int i = 1; i <= n; i ++ )
        iFile >> v[i] >> w[i];
    for(int i = 1; i <= n; i ++ )//遍历物品，物品编号从1开始
        for(int j = 1; j <= m; j ++ ) {//遍历背包容量，背包容量从1开始
            if(j < v[i]) dp[i][j] = dp[i - 1][j];//状态转移方程考虑是否放入物品i
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    cout << dp[n][m] << endl;
    return 0;
}
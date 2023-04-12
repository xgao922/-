#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int n = 3;
int f[n][n], arr[n][n];
int dx[2] = {1, 0}, dy[2] = {0, 1};

int dp(int x, int y) {
    int &v = f[x][y];
    if(v != -1) return v;
    v = 1;
    for(int i = 0; i < 2; i ++) {//枚举向右或向下两个方向
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < n)
            v = max(v, dp(a, b) + arr[a][b]);
    }
    return v;
}

int main() {
    ifstream iFile;
    iFile.open("in.txt");
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            iFile >> arr[i][j];
        }
    }
    memset(f, -1, sizeof f);
    int res = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            res = max(res, dp(i, j));
        }
    }
    cout << res << endl;
    return 0;
}
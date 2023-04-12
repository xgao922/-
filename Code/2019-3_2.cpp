#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
const int MOD = 998244353;//模数，验证算法的正确性
int f[N];

int main() {
    int x;
    cin >> x;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int n = 0; n <= 1000; n ++) {
        for(int i = 0; i < n; i ++) {
            f[n] = (f[n] + f[i] * f[n - i - 1]) % MOD;
        } 
    }
    cout << f[x] << endl;
    return 0;
}
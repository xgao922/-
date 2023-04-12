#include <iostream>

using namespace std;

int n;
long long f[25];

int main() {
    f[0] = 1;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);//Catalan数递推公式
    }
    cout << f[n] << endl;
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

long long F[1010];

//Catalan数，采用递归思想
long long f(int n) {
    long long ans = 0;
    if(F[n] != -1) return F[n];//记忆化搜索
    for(int i = 0; i < n; i ++) {
        ans += f(i) * f(n-i-1);
    }
    F[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    memset(F, -1, sizeof(F));
    F[0] = 1;
    cout << f(n) << endl;
    return 0;
}
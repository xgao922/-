#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], size;

void down(int u)
{
    int t = u;//t记录三个节点中的最小值
    if(u * 2 <= size && h[u * 2] < h[t]) t = u * 2;//如果左儿子存在且值小于h[t]
    if(u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;//如果右儿子存在且值小于h[t]
    if(u != t)//如果根结点不是最小值
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
    size = n;
    
    for(int i = n / 2; i; i -- ) down(i);
    
    while(m -- )
    {
        printf("%d ", h[1]);
        h[1] = h[size];//删除最小值
        size --;
        down(1);
    }
    return 0;
}
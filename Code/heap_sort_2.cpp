#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int heap[maxn];
int n, m;

void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while(j < high) {
        if(j + 1 <= high && heap[j + 1] < heap[j])
            j = j + 1;
        if(heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

void createHeap() {
    for(int i = n / 2; i >= 1; i --) {
        downAdjust(i, n);
    }
}

void heapSort() {
    createHeap();
    printf("%d ", heap[1]);
    for(int i = n; i >= n - m + 2; i --) {
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
        printf("%d ", heap[1]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &heap[i]);
    }
    heapSort();
    return 0;
}

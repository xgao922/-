#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int num;
    vector<int> heap;
    freopen("data.txt", "r", stdin);
    freopen("res.txt", "w", stdout);
    while(scanf("%d", &num) != EOF) {
        heap.push_back(num);
    }
    sort(heap.begin(), heap.end(), cmp);
    for(int i = 0; i < heap.size() * 0.3; i ++)
        cout << heap[i] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
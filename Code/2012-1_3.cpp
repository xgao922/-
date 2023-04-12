#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int num;
    priority_queue<int> heap;
    freopen("data.txt", "r", stdin);
    freopen("res.txt", "w", stdout);
    while(scanf("%d", &num) != EOF) {
        heap.push(num);
    }
    for(int i = 0; i < 300; i ++) {
        cout << heap.top() << endl;
        heap.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
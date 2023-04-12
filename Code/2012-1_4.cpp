#include <iostream>
#include <set>

using namespace std;

int main() {
    int num;
    multiset<int, greater<int>> heap;//heap中元素按降序排列，set默认升序排列
    freopen("data.txt", "r", stdin);
    freopen("res.txt", "w", stdout);
    while(scanf("%d", &num) != EOF) {
        heap.insert(num);
    }
    int m = 300;
    for(auto it = heap.begin(); it !=heap.end() && m --; it ++) {
        cout << *it << endl;
        cerr << *it << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include <iostream>

using namespace std;

const int maxn = 50;
int res = 0;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

int depth(int root) {
    if(root == -1) return 0;
    return max(depth(Node[root].lchild), depth(Node[root].rchild)) + 1;
}

int preOrder(int root) {
    if(root == -1) return 0;
    res = max(res, depth(Node[root].lchild) + depth(Node[root].rchild));
    preOrder(Node[root].lchild);
    preOrder(Node[root].rchild);
    return res;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) {
        cin >> Node[i].lchild >> Node[i].rchild;
    }
    res = preOrder(0);
    cout << res << endl;
    return 0;
}
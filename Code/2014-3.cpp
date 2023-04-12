#include <iostream>

using namespace std;

const int maxn = 10010;
struct node{//顺序存储二叉树
    int lchild;
    int rchild;
}Node[maxn];

bool flag[maxn] = {false};

void preOrder(int root) {
    if(root == -1) return;
    cout << root << " ";
    preOrder(Node[root].lchild);
    preOrder(Node[root].rchild);
}

void inOrder(int root) {
    if(root == -1) return;
    inOrder(Node[root].lchild);
    cout << root << " ";
    inOrder(Node[root].rchild);
}

void postOrder(int root) {
    if(root == -1) return;
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    cout << root << " ";
}

int main() {
    int n;
    cin >> n;
    int x, left, right;
    for(int i = 0; i < n; i ++) {
        cin >> i >> left >> right;
        Node[i].lchild = left;
        Node[i].rchild = right;
        flag[left] = true;
        flag[right] = true;
    }
    int root;
    for(int i = 0; i < n; i ++) {//找根结点，根结点没有具体指出不能默认为0
        if(flag[i] == false) root = i;
    }
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}
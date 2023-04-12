#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node{
    int id;
    int p;
    Node(int id, int p) : id(id), p(p) {}
};

struct cmp{
    bool operator() (const Node &a, const Node &b) {
        if(a.p == b.p) return a.id > b.id;
        return a.p < b.p;
    }
};

class CustomPriorityQueue{
private:
priority_queue<Node, vector<Node>, cmp> q;

public:    
    void ADD(int id, int p) {
        q.push(Node(id, p));
    }

    void NEXT() {
        cout << q.top().id << endl;
    }

    void REMOVE(int id) {
        vector<Node> buf;
        while(q.top().id != id) {
            buf.push_back(q.top());
            q.pop();
        }
        q.pop();
        for(auto node : buf) q.push(node);
    }

    void COUNT() {
        cout << q.size() << endl;
    }
};

int main() {
    CustomPriorityQueue cpq;
    int id, p;
    string str;
    cpq.ADD(1, 3);
    cpq.ADD(2, 1);
    cpq.ADD(3, 2);
    cpq.ADD(4, 2);
    while(1) {
        cin >> str;
        if(str == "ADD") {
            cin >> id >> p;
            cpq.ADD(id, p);
        }else if(str == "NEXT") {
            cpq.NEXT();
        }else if(str == "REMOVE") {
            cin >> id;
            cpq.REMOVE(id);
        }else if(str == "COUNT") {
            cpq.COUNT();
        }else break;
    }
    return 0;
}
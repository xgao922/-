#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int id;
    int p;
    Node(int id, int p) : id(id), p(p) {}
};

struct CompareNode {
    bool operator() (const Node &a, const Node &b) const {//重载函数调用运算符()
        if(a.p == b.p) return a.id > b.id;//优先级相同时，id小的任务优先
        return a.p < b.p;//从大到小，最大值优先
    }
};

class CustomPriorityQueue{
private:
    priority_queue<Node, vector<Node>, CompareNode> q;
    
public:
    void ADD(int id, int p) {
        q.push(Node(id, p));
    }

    void NEXT() {
        if(q.empty()) cout << -1 << endl;
        cout << q.top().id << endl;
    }

    void REMOVE(int id) {//暴力
        vector<Node> buf;
        while(!q.empty()) {
            if(q.top().id != id) buf.push_back(q.top());
            q.pop();
        }
        for(const auto& node : buf) q.push(node);
    }

    void COUNT() {
        cout << q.size() << endl;
    }
};



int main() {
    CustomPriorityQueue cpq;
    cpq.ADD(1, 3);
    cpq.ADD(2, 1);
    cpq.ADD(3, 2);
    cpq.ADD(4, 2);
    int id, p;
    string str;
    while(1) {
        cin >> str;
        if(str == "ADD") {
            cin >> id >> p;
            cpq.ADD(id, p);
        } else if(str == "NEXT") {
            cpq.NEXT();
        } else if(str == "REMOVE") {
            cin >> id;
            cpq.REMOVE(id);
        } else if(str == "COUNT"){
            cpq.COUNT();
        } else break;
    }
    return 0;
}
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    map<char, int> m;
    priority_queue<int, vector<int>, greater<int>> q; //优先队列中的元素是int型而不是char型，存储每个字符的出现次数而非字符本身
    for(int i = 0; i < str.size(); i ++) {//统计每个字符的出现次数
        if(m.find(str[i]) == m.end()) m[str[i]] = 1;
        else m[str[i]] ++;
    }
    for(auto it = m.begin(); it != m.end(); it ++) q.push(it->second);//从小到大排列每个字符的出现次数
    int ans = 0;
    while(q.size() != 1) {//优先队列的队首的两个元素之和作为新的节点权值进入优先队列
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;//ans为哈夫曼树带权路径长度和，即非叶节点的权值之和
        q.push(a + b);
    }
    cout << ans << endl;
    return 0;
}


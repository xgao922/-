#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<char> stk;
    for(int i = 0; i < s.size(); i ++ ) {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') stk.push(s[i]);
        else if(s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '?') {
            while(!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            cout << s[i];
        }
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}

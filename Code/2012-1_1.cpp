#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 1000, m = 300, s;

void down(int u, vector<int>& h) {
    int t = u;
    if(u * 2 + 1 <= s && h[u * 2 + 1] > h[t]) t = u * 2 + 1;
    if(u * 2 + 2 <= s && h[u * 2 + 2] > h[t]) t = u * 2 + 2;
    if(u != t) {
        swap(h[u], h[t]);
        down(t, h);
    }
}

int main() {
    ifstream file("data.txt");
    vector<int> h;
    int num;

    if(file.is_open()) {
        string line;
        while(getline(file, line)) {
            stringstream ss(line);
            while(ss >> num) {
                h.push_back(num);
            }
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
        return 1;
    }

    s = n - 1;
    for(int i = (s - 1) / 2; i >= 0; i -- ) down(i, h);

    ofstream res("res.txt");

    while(m --) {
        if(res.is_open()) res << h[0] << endl;
        printf("%d\n", h[0]);
        swap(h[0], h[s]);
        s --;
        down(0, h);
    }

    res.close();

    return 0;
}
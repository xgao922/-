#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int left;
    int right;
};
Node positions[10];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> positions[i].left >> positions[i].right;
    }
    int temp = positions[n-1].right - positions[0].left + 1;
    vector<int> distance(temp);
    for(int i = positions[0].left; i <= positions[n-1].right; i ++) {
        for(int j = 0; j < n; j ++) {
            if(positions[j].right < i) distance[i] += i - positions[j].right;
            else if(positions[j].left > i) distance[i] += positions[j].left - i;
        }
    }
    int min = distance[positions[0].left];
    for(int i = positions[0].left; i <= positions[n-1].right; i ++) {
        if(distance[i] < min) min = distance[i];
    }
    cout << min << endl;
    return 0;
}
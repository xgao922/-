#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int n =3;
    int arr[n][n];
    ifstream iFile;
    iFile.open("in.txt");
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            iFile >> arr[i][j];
        }
    }
    cout << arr[2][2];
    return 0;
}
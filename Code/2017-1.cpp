#define maxsize 50

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[maxsize];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << "��λ��Ϊ��";
    if(n % 2 == 1){
        cout << a[n/2];
    }else{//nΪż��ʱ����λ��Ϊ������м���������ƽ��ֵ�����ܲ�����
        cout << (a[n/2-1]+a[n/2])/2.0;
    }
    return 0;
}
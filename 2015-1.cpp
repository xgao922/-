#include <iostream>

using namespace std;

int main() {
    int x, y;
    cout << "�����εĳ�Ϊ��" ;
    cin >> x;
    cout << "�����εĿ�Ϊ��" ;
    cin >> y;
    int ans = 1;
    while(x != y)
    {
        int temp = abs(x - y);//temp�ݴ�x-y�ľ���ֵ
        y = min(x, y);//yΪx,y�еĽ�Сֵ
        x = temp;//��temp����x
        ans ++;
    }
    cout << "����ܵõ��������θ���Ϊ��" << ans << endl;
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

// �ҳ����ֵ�ʹδ�ֵ����sort�������򼴿�
int main()
{
	int a[4];
	int x, y, z, w;
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4);
	cout << a[2] + a[3];
	return 0;
}

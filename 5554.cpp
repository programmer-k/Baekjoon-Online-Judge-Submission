/*
���� �̸� : 5554.cpp
������ : ������
���� ��¥ : 2017�� 7�� 15��
���α׷� �뵵 : �̵� �ð��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int homeToSch, schToPc, PcToAca, acaToHome;

	// �Է�
	cin >> homeToSch >> schToPc >> PcToAca >> acaToHome;

	// ���
	int sec = homeToSch + schToPc + PcToAca + acaToHome;
	int min = sec / 60;
	sec %= 60;

	// ���
	cout << min << endl;
	cout << sec << endl;
	return 0;
}
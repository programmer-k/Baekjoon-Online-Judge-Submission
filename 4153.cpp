/*
���� �̸� : 4153.cpp
������ : ������
���� ��¥ : 2017�� 7�� 25��
���α׷� �뵵 : ���� �ﰢ������ �Ǵ��Ѵ�.
*/

#include <iostream>
using namespace std;

/* ���� ū ���� ã�Ƽ� ptr1�� ����Ű�� ������ ���� ��ȯ�ϴ� �Լ��̴�. */
void FindLargest(int * ptr1, int * ptr2, int * ptr3)
{
	if (*ptr1 >= *ptr2 && *ptr1 >= *ptr3)
		return;
	else if (*ptr2 >= *ptr1 && *ptr2 >= *ptr3)
	{
		int temp = *ptr2;
		*ptr2 = *ptr1;
		*ptr1 = temp;
	}
	else
	{
		int temp = *ptr3;
		*ptr3 = *ptr1;
		*ptr1 = temp;
	}

}

int main(void)
{
	while (true)
	{
		int side1, side2, side3;

		// �Է�
		cin >> side1 >> side2 >> side3;

		// �Է��� 0, 0, 0�̸� ���α׷� ����
		if (side1 == 0 && side2 == 0 && side3 == 0)
			break;

		// ���� ū ���� side1�� �����ϱ�
		FindLargest(&side1, &side2, &side3);

		// ���� �ﰢ������ �����ϱ�
		if (side1 * side1 == side2 * side2 + side3 * side3)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}
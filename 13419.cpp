#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int tc;

	// �Է�
	cin >> tc;

	// tc��ŭ �ݺ�
	for (int i = 0; i < tc; i++)
	{
		string str;
		string ans1 = "";
		string ans2 = "";

		// ���ڿ� �Է�
		cin >> str;

		int idx1 = 0;
		int idx2 = 1;
		while (true)
		{
			// �� ���ھ� �׾Ƴ���
			ans1 += str[idx1];

			// �� ���� �Ѿ�� ���� �� ����
			idx1 += 2;

			// �ε��� ���� �Ѿ�� ���̱�
			if (idx1 >= str.size())
			{
				idx1 = idx1 % str.size();
			}

			if (idx1 == 0)
				break;
		}
		cout << ans1 << endl;

		if (str.size() == 1)
			cout << str << endl;
		else
		{
			while (true)
			{
				// �� ���ھ� �׾Ƴ���
				ans2 += str[idx2];

				// �� ���� �Ѿ�� ���� �� ����
				idx2 += 2;

				// �ε��� ���� �Ѿ�� ���̱�
				if (idx2 >= str.size())
				{
					idx2 = idx2 % str.size();
				}
				if (idx2 == 1)
					break;
			}
			cout << ans2 << endl;
		}
	}
	return 0;
}


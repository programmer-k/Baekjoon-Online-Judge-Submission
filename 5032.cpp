/*
���� �̸� : 5032.cpp
������ : ������
���� ��¥ : 2017�� 7�� 25��
���α׷� �뵵 : �ع��̰� ���� �� �ִ� ź�������� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int emptyBotl, findBotl, changeBotl;
	int totalBotl, ans = 0;

	// �Է�
	cin >> emptyBotl >> findBotl >> changeBotl;

	// ��� �� ���
	totalBotl = emptyBotl + findBotl;	// ������ �ִ� �� �� �� ���

	while (totalBotl / changeBotl > 0)	// totalBotl / changeBotl�� ���� 0���� ũ�� ans�� ���� �ö� �� �����Ƿ� �ݺ��� ����Ѵ�.
	{
		int temp = totalBotl / changeBotl;
		ans += temp;	// ���� ������ ������ �߰��Ѵ�.
		totalBotl = temp + totalBotl % changeBotl;	// ������ �ִ� �� �� �� �ٽ� ����
	}
	cout << ans << endl;
	return 0;

}
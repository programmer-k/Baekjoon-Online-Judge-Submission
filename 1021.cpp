#include <iostream>
#include <vector>
using namespace std;

void MoveLeft(vector<int>& vec,int& cnt);
void MoveRight(vector<int>& vec, int& cnt);
int CalOffset(vector<int>& vec, int val);

int main(void)
{
	int n, m, cnt = 0, index[51];
	vector<int> vec;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> index[i];

	// initialization
	for (int i = 1; i <= n; i++)
		vec.push_back(i);

	for (int i = 1; i <= m; i++)
	{
		int offset = CalOffset(vec, index[i]);
		
		//cout << "offset: " << offset << endl;
		while (offset > 0)
		{
			MoveLeft(vec, cnt);
			offset--;
		}

		while (offset < 0)
		{
			MoveRight(vec, cnt);
			offset++;
		}

		vec.erase(vec.begin());

		//cout << "cnt: " << cnt << endl;
	}

	cout << cnt << endl;

	return 0;
}

void MoveLeft(vector<int>& vec, int& cnt)
{
	vec.push_back(vec.front());
	vec.erase(vec.begin());
	cnt++;
}

void MoveRight(vector<int>& vec, int& cnt)
{
	vec.insert(vec.begin(), vec.back());
	vec.pop_back();
	cnt++;
}

int CalOffset(vector<int>& vec, int val)
{
	int posOffset, negOffset;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == val)
		{
			posOffset = i;
			break;
		}
	}

	for (unsigned int i = vec.size() - 1; i >= 0; i--)
	{
		if (vec[i] == val)
		{
			negOffset = -((int) (vec.size() - i));
			break;
		}
	}

	//cout << "posOffset: " << posOffset << endl;
	//cout << "negOffset: " << negOffset << endl;

	if (abs(posOffset) <= abs(negOffset))
		return posOffset;
	else
		return negOffset;
}
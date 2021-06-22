#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int length;
		cin >> length;
		vec.push_back(length);
	}

	int cnt = 0;
	vector<int> tens;
	for (int i = 0; i < n; i++)
	{
		if (vec[i] == 10)
			cnt++;
		else if (vec[i] % 10 == 0 && m > 0)
		{
			tens.push_back(vec[i]);
		}
	}

	sort(tens.begin(), tens.end());
	for (int i = 0; i < tens.size(); i++)
	{
		int val = tens[i] / 10 - 1;
		if (val > m)
		{
			cnt += m;
			m = 0;
			break;
		}
		else
		{
			cnt += val + 1;
			m -= val;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (vec[i] > 10 && vec[i] % 10 != 0)
		{
			int val = vec[i] / 10;
			if (val > m)
			{
				cnt += m;
				break;
			}
			else
			{
				cnt += val;
				m -= val;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}
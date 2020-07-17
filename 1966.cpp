#include <iostream>
#include <vector>
using namespace std;

void setMax(int& max, const vector<int>& vec);

int main(void)
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n, idx;
		cin >> n >> idx;

		vector<int> vec(n);
		// cout << n << endl;
		for (int j = 0; j < n; j++)
			cin >> vec[j];

		int max = -1;
		setMax(max, vec);

		int cnt = 0;
		while (true)
		{
			int front = vec[0];
			vec.erase(vec.begin());

			if (front == max)
			{
				cnt++;
				max = -1;
				setMax(max, vec);
				if (idx == 0)
					break;
			}
			else
				vec.push_back(front);
			if (idx == 0)
				idx = vec.size() - 1;
			else
				idx--;

			// cout << "idx: " << idx << endl;
			// cout << "front: " << front << endl;
			// cout << "max: " << max << endl;
			// cout << endl;
		}

		cout << cnt << '\n';
	}

	return 0;
}

void setMax(int& max, const vector<int>& vec)
{
	for (int j = 0; j < vec.size(); j++)
		if (vec[j] > max)
			max = vec[j];

}
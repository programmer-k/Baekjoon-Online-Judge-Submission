#include <iostream>
using namespace std;

int main(void)
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n, s, d;
        cin >> n >> s >> d;
        int distances[200], values[200];
        for (int j = 0; j < n; j++)
            cin >> distances[j] >> values[j];
        int distance = s * d;
        int total = 0;
        for (int j = 0; j < n; j++)
            if (distances[j] <= distance)
                total += values[j];
        cout << "Data Set " << i + 1 << ":\n";
        cout << total << "\n\n";
    }
    return 0;
}
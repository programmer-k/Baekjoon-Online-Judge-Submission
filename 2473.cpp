#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[5000];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
}

void Solve()
{
    sort(arr, arr + n);
    /*cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';*/

    int answer[3];
    long long minVal = 3234567890;
    for (int i = 0; i < n; i++)
    {
        long long offset = arr[i];
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (left == i)
            {
                left++;
                continue;
            }
            else if (right == i)
            {
                right--;
                continue;
            }

            long long total = arr[left] + arr[right] + offset;
            long long absTotal = abs(total);
            
            if (absTotal < minVal)
            {
                minVal = absTotal;
                answer[0] = arr[left];
                answer[1] = arr[right];
                answer[2] = offset;
                //cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << ": " << total << '\n';
            }

            if (total > 0)
                right--;
            else
                left++;
        }
    }

    sort(answer, answer + 3);
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}
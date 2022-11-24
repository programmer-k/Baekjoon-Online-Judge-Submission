#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> primeNums;
bool isPrime[4000001];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
}

void CalcPrime()
{
    for (int i = 2; i <= 4000000; i++)
        isPrime[i] = true;

    for (int i = 2; i <= sqrt(4000000); i++)
    {
        if (!isPrime[i])
            continue;
        
        for (int j = i * 2; j <= 4000000; j += i)
            isPrime[j] = false;
    }

    for (int i = 2; i <= 4000000; i++)
        if (isPrime[i])
            primeNums.push_back(i);
}

void Solve()
{
    CalcPrime();

    int cnt = 0;
    int sum = primeNums[0];
    size_t start = 0, end = 0;
    while (end < primeNums.size() && primeNums[end] <= n)
    {
        //cout << "sum: " << sum << '\n';
        //cout << primeNums[start] << ", " << primeNums[end] << '\n';
        if (sum == n)
        {
            cnt++;
            //cout << primeNums[start] << ", " << primeNums[end] << '\n';
        }
        
        if (sum < n)
        {
            if (end != primeNums.size() - 1)
                sum += primeNums[++end];
            else
                end++;
        }
        else
        {
            sum -= primeNums[start++];
        }
    }

    cout << cnt << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n, k;
vector<int> vec;
//int numCnt[101];

void GetInput1()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2()
{
    cin >> n >> k;
    vec.clear();
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
}
/*
bool MostCommon()
{
    int countK = numCnt[k];
    for (int i = 1; i <= 100; i++)
    {
        if (k != i && countK <= numCnt[i])
            return false;
    }

    return true;
}

void Calc()
{
    // i is search start point.
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int val = vec[j];
            numCnt[val]++;

            if ()
            
            if (countK > )
        }
    }
}
*/

void Solve()
{
    for (int i = 0; i < t; i++)
    {
        GetInput2();
        vector<int>::iterator it = find(vec.begin(), vec.end(), k);
        if (it != vec.end())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main(void)
{
    GetInput1();
    Solve();
    return 0;
}